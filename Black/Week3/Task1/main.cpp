#include <cstddef>
#include <vector>
#include <algorithm>
#include "test_runner.h"

using namespace std;

struct Nucleotide {
    int Symbol;
    size_t Position;
    int ChromosomeNum;
    int GeneNum;
    bool IsMarked;
    char ServiceInfo;
};

vector<char> nucl = {'A', 'T', 'G', 'C'};
vector<bool> boolk = {true, false};

struct CompactNucleotide {
    size_t Symbol:2;
    size_t Position:32;
    size_t ChromosomeNum:6;
    size_t GeneNum:15;
    size_t IsMarked:1;
    size_t ServiceInfo:8;
};


bool operator == (const Nucleotide& lhs, const Nucleotide& rhs) {
    return (lhs.Symbol == rhs.Symbol)
           && (lhs.Position == rhs.Position)
           && (lhs.ChromosomeNum == rhs.ChromosomeNum)
           && (lhs.GeneNum == rhs.GeneNum)
           && (lhs.IsMarked == rhs.IsMarked)
           && (lhs.ServiceInfo == rhs.ServiceInfo);
}


CompactNucleotide Compress(const Nucleotide& n) {
    size_t symb = find(nucl.begin(), nucl.end(), static_cast<char>(n.Symbol)) - nucl.begin();
    size_t pos = n.Position;
    size_t chrom = n.ChromosomeNum;
    size_t gene = n.GeneNum;
    size_t is_marked = n.IsMarked ? 0 : 1;
    size_t serv = n.ServiceInfo;

    return {symb, pos, chrom, gene, is_marked, serv};
};


Nucleotide Decompress(const CompactNucleotide& cn) {
    return {nucl[cn.Symbol], cn.Position, cn.ChromosomeNum, cn.GeneNum,
            boolk[cn.IsMarked], static_cast<char>(cn.ServiceInfo)};
}

void TestSize() {
    ASSERT(sizeof(CompactNucleotide) <= 8);
}

void TestCompressDecompress() {
    Nucleotide source;

    source.Symbol = 'T';
    source.Position = 1'000'000'000;
    source.ChromosomeNum = 48;
    source.GeneNum = 1'000;
    source.IsMarked = true;
    source.ServiceInfo = 'Test';

    CompactNucleotide compressedSource = Compress(source);
    Nucleotide decompressedSource = Decompress(compressedSource);

    ASSERT(source == decompressedSource);
}

int main() {
    TestRunner tr;

    RUN_TEST(tr, TestSize);
    RUN_TEST(tr, TestCompressDecompress);

    return 0;
}
