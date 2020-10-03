#include "saveload.h"

#include "test_runner.h"

#include <map>
#include <sstream>
#include <string>

using namespace std;

void TestSaveLoad() {
    map<uint32_t, string> m = {
            {1, "hello"},
            {2, "bye"},
    };
    stringstream ss;
    Serialize(m, ss);
    auto s = ss.str();

    ASSERT_EQUAL(s.size(), 40);

    // Р Р°Р·РјРµСЂ map (8 Р±Р°Р№С‚, С‚Р°Рє РєР°Рє СЌС‚Рѕ size_t)
    ASSERT_EQUAL(s[0],  0x02);
    ASSERT_EQUAL(s[1],  0x00);
    ASSERT_EQUAL(s[2],  0x00);
    ASSERT_EQUAL(s[3],  0x00);
    ASSERT_EQUAL(s[4],  0x00);
    ASSERT_EQUAL(s[5],  0x00);
    ASSERT_EQUAL(s[6],  0x00);
    ASSERT_EQUAL(s[7],  0x00);

    // РљР»СЋС‡ 1 (4 Р±Р°Р№С‚Р°, С‚Р°Рє РєР°Рє СЌС‚Рѕ uint32_t)
    ASSERT_EQUAL(s[8],  0x01);
    ASSERT_EQUAL(s[9],  0x00);
    ASSERT_EQUAL(s[10], 0x00);
    ASSERT_EQUAL(s[11], 0x00);

    // Р—РЅР°С‡РµРЅРёРµ: СЃРЅР°С‡Р°Р»Р° СЂР°Р·РјРµСЂ СЃС‚СЂРѕРєРё (size_t)
    ASSERT_EQUAL(s[12], 0x05);
    ASSERT_EQUAL(s[13], 0x00);
    ASSERT_EQUAL(s[14], 0x00);
    ASSERT_EQUAL(s[15], 0x00);
    ASSERT_EQUAL(s[16], 0x00);
    ASSERT_EQUAL(s[17], 0x00);
    ASSERT_EQUAL(s[18], 0x00);
    ASSERT_EQUAL(s[19], 0x00);

    // РўРµРїРµСЂСЊ СЃР°РјР° СЃС‚СЂРѕРєР° (ASCII-РєРѕРґС‹):
    ASSERT_EQUAL(s[20], 0x68);  // 'h'
    ASSERT_EQUAL(s[21], 0x65);  // 'e'
    ASSERT_EQUAL(s[22], 0x6c);  // 'l'
    ASSERT_EQUAL(s[23], 0x6c);  // 'l'
    ASSERT_EQUAL(s[24], 0x6f);  // 'o'

    // РљР»СЋС‡ 2
    ASSERT_EQUAL(s[25], 0x02);
    ASSERT_EQUAL(s[26], 0x00);
    ASSERT_EQUAL(s[27], 0x00);
    ASSERT_EQUAL(s[28], 0x00);

    // Р—РЅР°С‡РµРЅРёРµ РєР»СЋС‡Р° 2: СЂР°Р·РјРµСЂ
    ASSERT_EQUAL(s[29], 0x03);
    ASSERT_EQUAL(s[30], 0x00);
    ASSERT_EQUAL(s[31], 0x00);
    ASSERT_EQUAL(s[32], 0x00);
    ASSERT_EQUAL(s[33], 0x00);
    ASSERT_EQUAL(s[34], 0x00);
    ASSERT_EQUAL(s[35], 0x00);
    ASSERT_EQUAL(s[36], 0x00);

    // Р—РЅР°С‡РµРЅРёРµ РєР»СЋС‡Р° 2: СЃС‚СЂРѕРєР°
    ASSERT_EQUAL(s[37], 0x62);  // 'b'
    ASSERT_EQUAL(s[38], 0x79);  // 'y'
    ASSERT_EQUAL(s[39], 0x65);  // 'e'

    map<uint32_t, string> m2;
    Deserialize(ss, m2);

    ASSERT_EQUAL(m, m2);
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestSaveLoad);
    return 0;
}