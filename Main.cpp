#include "Main.hpp"
#include "YSMF.hpp"

void helper(std::string file){
    std::cout << "Usage:: " << file << " -row <n_row> -col <n_col> [-fill <\%fill>] [-t <n_thread>]" << std::endl << std::endl;
    std::cout << "Default values:" << std::endl;
    std::cout << "\tn_row : 100" << std::endl;
    std::cout << "\tn_col : 100" << std::endl;
    std::cout << "\t\%fill : 10" << std::endl;
    std::cout << "\tn_thread : 1" << std::endl;
}

int main(int argc, char** argv)
{
	if (argc < 1) {
        helper(argv[0]);
        return 0;
    }
    //default value
    int n_col = 100;
    int n_row = 100;
    int fill  = 10;
    int n_thread = 1;
	//check other option
    int i = 2;
    while( i < argc){
        if(strcmp(argv[i],"-row") == 0){
            if(i+1 < argc){
                n_row = atoi(argv[i+1]);
            }
            else{
                std::cerr << "Missing value for -row"<< std::endl;
                helper(argv[0]);
                return 1;
            }
        }
        else if(strcmp(argv[i],"-col") == 0){
            if(i+1 < argc){
                n_col = atoi(argv[i+1]);
            }
            else{
                std::cerr << "Missing value for -col"<< std::endl;
                helper(argv[0]);
                return 1;
            }
        }
        else if(strcmp(argv[i],"-fill") == 0){
            if(i+1 < argc){
                fill = atoi(argv[i+1]);
            }
            else{
                std::cerr << "Missing value for -fill"<< std::endl;
                helper(argv[0]);
                return 1;
            }
        }
        else if(strcmp(argv[i],"-t") == 0){
            if(i+1 < argc){
                n_thread = atoi(argv[i+1]);
            }
            else{
                std::cerr << "Missing value for -t"<< std::endl;
                helper(argv[0]);
                return 1;
            }
        }

        i++;
    }
    //Print options that will use
    std::cout << "Selected values:" << std::endl;
    std::cout << "\tn_row: " << n_row << std::endl;
    std::cout << "\tn_col: " << n_col << std::endl;
    std::cout << "\t\%fill: " << fill << std::endl;
    std::cout << "\tn_thread: " << n_thread << std::endl;

    YSMF *matrix = new YSMF(n_row, n_col, fill);
    matrix->print();
    std::cout << "END :D" << std::endl;
}