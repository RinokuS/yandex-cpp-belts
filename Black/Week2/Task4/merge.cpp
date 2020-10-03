#include "yellow_pages.h"

#include <algorithm>
#include <tuple>

namespace YellowPages {

    namespace {

        template<typename T>
        Company MergeSingleMessage(const Signals &signals,
                                   const google::protobuf::FieldDescriptor *field,
                                   const T &getPriority) {
            const auto *descriptor = Company::default_instance().GetDescriptor();
            const auto *reflection = Company::default_instance().GetReflection();
            Company res;
            google::protobuf::int64 res_priority = -1;

            for (const auto &signal : signals) {
                const auto &company = signal.company();
                const auto priority = getPriority(signal);

                if (reflection->HasField(company, field) && (priority > res_priority)) {
                    reflection->MutableMessage(&res, field)
                            ->CopyFrom(reflection->GetMessage(company, field));
                    res_priority = priority;
                }
            }

            return res;
        }

        template <typename T>
        Company MergeRepeatedMessage(const Signals& signals,
                                     const google::protobuf::FieldDescriptor* field,
                                     const T& getPriority) {
            const auto* descriptor = Company::default_instance().GetDescriptor();
            const auto* reflection = Company::default_instance().GetReflection();
            google::protobuf::int64 res_priority = -1;

            for (const auto& signal : signals) {
                const auto& company = signal.company();
                const auto priority = getPriority(signal);

                if (reflection->FieldSize(company, field) && (priority > res_priority)) {
                    res_priority = priority;
                }
            }

            std::unordered_set<std::string> field_values;
            for (const auto& signal : signals) {
                const auto& company = signal.company();
                const auto priority = getPriority(signal);

                if (const auto sz = reflection->FieldSize(company, field);
                        sz && (priority == res_priority)) {
                    for (int i = 0; i < sz; ++i) {
                        field_values.insert(reflection->GetRepeatedMessage(company, field, i)
                                                    .SerializeAsString());
                    }
                }
            }

            Company res;
            for (const auto& data : field_values) {
                reflection->AddMessage(&res, field)->ParseFromString(data);
            }

            return res;
        }
    }

    Company Merge(const Signals& signals, const Providers& providers) {
        // Наивная неправильная реализация: берём все данные из самого первого сигнала, никак не учитываем приоритеты
        if (signals.empty())
            return Company();

        const auto get_priority = [&](const Signal& signal){
            return providers.at(signal.provider_id()).priority();
        };
        const auto single_call = [&](const std::string& field){
            return MergeSingleMessage(signals, Company::descriptor()->FindFieldByName(field), get_priority);
        };
        const auto multiple_call = [&](const std::string& field){
            return MergeRepeatedMessage(signals, Company::descriptor()->FindFieldByName(field), get_priority);
        };

#define single(f) single_call(#f).f()
#define repeated(f) multiple_call(#f).f()

        Company company;
        company.mutable_address()->CopyFrom(single(address));
        company.mutable_working_time()->CopyFrom(single(working_time));
        company.mutable_names()->CopyFrom(repeated(names));
        company.mutable_phones()->CopyFrom(repeated(phones));
        company.mutable_urls()->CopyFrom(repeated(urls));
        return company;
    }

}
