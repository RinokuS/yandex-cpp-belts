#pragma once

#include <utility>

namespace RAII{
    template <typename Provider>
    class Booking{
    private:
        Provider* provider_;
        int id_;
    public:
        Booking(Provider *p, int i) : provider_(p), id_(i){
        }
        Booking(const Booking&) = delete;
        Booking(Booking&& other){
            provider_ = std::move(other.provider_);
            id_ = std::move(other.id_);

            other.provider_ = nullptr;
        }

        Booking& operator=(const Booking&) = delete;
        Booking& operator=(Booking&& other) noexcept {
            provider_ = std::move(other.provider_);
            id_ = std::move(other.id_);

            other.provider_ = nullptr;

            return *this;
        }

        ~Booking(){
            if (provider_)
                provider_->CancelOrComplete(*this);
        }
    };
}
