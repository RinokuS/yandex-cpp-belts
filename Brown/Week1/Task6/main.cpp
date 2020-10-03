#include "test_runner.h"

#include <iostream>
#include <map>
#include <string>
#include <unordered_map>

using namespace std;

struct Record {
  string id;
  string title;
  string user;
  int timestamp;
  int karma;
};

typedef string ID;

struct DataElement
{
    Record record;
    multimap<string, const Record*>::iterator user_index;
    multimap<int, const Record*>::iterator timestamp_index;
    multimap<int, const Record*>::iterator karma_index;
};

// Р РµР°Р»РёР·СѓР№С‚Рµ СЌС‚РѕС‚ РєР»Р°СЃСЃ
class Database {
private:
    unordered_map<ID, DataElement> _data;
    multimap<int, const Record*> _secondaryKarmaIdx;
    multimap<int, const Record*> _secondaryTimestampIdx;
    multimap<string, const Record*> _secondaryUserIdx;
public:
  bool Put(const Record& record){
      const auto is_success = _data.insert({record.id, {record, {}, {}, {}}});

      if (!is_success.second){
          return false;
      }

      const auto iter = is_success.first;
      auto& data = iter->second;
      auto recPointer = &data.record;

      data.karma_index = _secondaryKarmaIdx.insert({record.karma, recPointer});
      data.user_index = _secondaryUserIdx.insert({record.user, recPointer});
      data.timestamp_index = _secondaryTimestampIdx.insert({record.timestamp, recPointer});

      return true;
  }
  const Record* GetById(const string& id) const{
      const auto iter = _data.find(id);

      if (iter == _data.end()){
          return nullptr;
      } else{
          return &iter->second.record;
      }
  }
  bool Erase(const string& id){
      const auto iter = _data.find(id);

      if (iter == _data.end()){
          return false;
      } else{
          const auto& secondary_index = iter->second;
          _secondaryUserIdx.erase(secondary_index.user_index);
          _secondaryTimestampIdx.erase(secondary_index.timestamp_index);
          _secondaryKarmaIdx.erase(secondary_index.karma_index);
          _data.erase(iter);
          return true;
      }
  }

  template <typename Callback>
  void RangeByTimestamp(int low, int high, Callback callback) const{
      const auto lower_bound = _secondaryTimestampIdx.lower_bound(low);
      const auto upper_bound = _secondaryTimestampIdx.upper_bound(high);

      for(auto iter = lower_bound; iter != upper_bound; iter++){
          if(!callback(*iter->second))
              return;
      }
  }

  template <typename Callback>
  void RangeByKarma(int low, int high, Callback callback) const{
      const auto lower_bound = _secondaryKarmaIdx.lower_bound(low);
      const auto upper_bound = _secondaryKarmaIdx.upper_bound(high);

      for(auto iter = lower_bound; iter != upper_bound; iter++){
          if(!callback(*iter->second))
              return;
      }
  }

  template <typename Callback>
  void AllByUser(const string& user, Callback callback) const{
      const auto equal_range = _secondaryUserIdx.equal_range(user);

      for(auto iter = equal_range.first; iter != equal_range.second; iter++){
          if(!callback(*iter->second))
              return;
      }
  }
};

void TestRangeBoundaries() {
  const int good_karma = 1000;
  const int bad_karma = -10;

  Database db;
  db.Put({"id1", "Hello there", "master", 1536107260, good_karma});
  db.Put({"id2", "O>>-<", "general2", 1536107260, bad_karma});

  int count = 0;
  db.RangeByKarma(bad_karma, good_karma, [&count](const Record&) {
    ++count;
    return true;
  });

  ASSERT_EQUAL(2, count);
}

void TestSameUser() {
  Database db;
  db.Put({"id1", "Don't sell", "master", 1536107260, 1000});
  db.Put({"id2", "Rethink life", "master", 1536107260, 2000});

  int count = 0;
  db.AllByUser("master", [&count](const Record&) {
    ++count;
    return true;
  });

  ASSERT_EQUAL(2, count);
}

void TestReplacement() {
  const string final_body = "Feeling sad";

  Database db;
  db.Put({"id", "Have a hand", "not-master", 1536107260, 10});
  db.Erase("id");
  db.Put({"id", final_body, "not-master", 1536107260, -10});

  auto record = db.GetById("id");
  ASSERT(record != nullptr);
  ASSERT_EQUAL(final_body, record->title);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestRangeBoundaries);
  RUN_TEST(tr, TestSameUser);
  RUN_TEST(tr, TestReplacement);
  return 0;
}