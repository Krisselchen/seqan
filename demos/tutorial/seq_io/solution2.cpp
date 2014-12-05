#include <seqan/seq_io.h>

int main(int argc, char const ** argv)
{
    if (argc < 2)
    {
        std::cerr << "USAGE: basic_seq_io_example FILENAME\n";
        return 1;
    }

    seqan::CharString id;
    seqan::Dna5String seq;

    seqan::SeqFileIn seqFileIn;
    if (!open(seqFileIn, argv[1]))
    {
        std::cerr << "ERROR: Could not open the file.\n";
        return 1;
    }

    try
    {
        readRecord(id, seq, seqFileIn);
    }
    catch (seqan::Exception const & e)
    {
        std::cout << "ERROR: " << e.what() << std::endl;
        return 1;
    }

    std::cout << id << '\t' << seq << '\n';

    return 0;
}
