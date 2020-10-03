#include "Common.h"

#include <mutex>
#include <unordered_map>
#include <map>
#include <memory>
#include <string>

using namespace std;

namespace Books{
    class Unpacker : IBooksUnpacker{
    public:
        std::unique_ptr<IBook> UnpackBook(const std::string& book_name) override {

        }
    };
}

class LruCache : public ICache {
public:
    LruCache(
            shared_ptr<IBooksUnpacker> books_unpacker,
            const Settings& settings
    ) : settings_(settings), free_memory_(settings.max_memory), books_unpacker_(move(books_unpacker)) {

    }

    BookPtr GetBook(const string& book_name) override {
        mutex_.lock();

        Node find_node = name_to_book_.extract(book_name);
        BookPtr result;

        if(find_node.empty()){
            result =  GetNewBook(book_name);
        } else{
            result = GetExistingBook(find_node);
        }

        return [&]{
            mutex_.unlock();
            return result;
        }();
    }

private:
    int counter = -2'147'483'000;
    const Settings settings_;
    const shared_ptr<IBooksUnpacker> books_unpacker_;
    size_t free_memory_;
    mutex mutex_ = mutex();

    using Node = unordered_map<string, pair<int, BookPtr>>::node_type;
    map<int, string> priority_to_name_;
    unordered_map<string, pair<int, BookPtr>> name_to_book_;

    BookPtr GetExistingBook(Node& node){
        BookPtr result = node.mapped().second;

        auto map_node = priority_to_name_.extract(node.mapped().first);
        map_node.key() = ++counter;
        priority_to_name_.insert(move(map_node));

        node.mapped().first = counter;
        name_to_book_.insert(std::move(node));

        return result;
    }

    BookPtr GetNewBook(const std::string& book_name){
        BookPtr result = books_unpacker_->UnpackBook(book_name);

        const size_t wanted_memory = result->GetContent().size();

        if (wanted_memory > settings_.max_memory){
            return result;
        } else if (wanted_memory > free_memory_){
            ClearCache(wanted_memory);
        }

        free_memory_ -= wanted_memory;
        priority_to_name_.insert({++counter, result->GetName()});
        name_to_book_.insert({result->GetName(), make_pair(counter, result)});

        return result;
    }

    void ClearCache(size_t wanted_memory){
        while(!name_to_book_.empty()){
            auto it = priority_to_name_.begin();
            auto second_it = name_to_book_.find(it->second);

            free_memory_ += second_it->second.second->GetContent().size();
            name_to_book_.erase(second_it);
            priority_to_name_.erase(it);

            if(free_memory_ >= wanted_memory){
                break;
            }
        }

        if (name_to_book_.empty()){
            counter = -2'147'483'000;
        }
    }
};


unique_ptr<ICache> MakeCache(
        shared_ptr<IBooksUnpacker> books_unpacker,
        const ICache::Settings& settings
) {
    return make_unique<LruCache>(move(books_unpacker), settings);
}