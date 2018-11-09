#include "common.h"
#include "BaseProcessor.h"
#include "ConservativeRotation.h"
#include "NonConservativeRotation.h"
#include "Scaling.h"

int main(int argc, char* argv[]) {
    if (argc < 3) {
        cerr << ERROR_MESS_INVALID_ARGUMENTS << endl;
        return -1;
    }

    char* pathToImage = argv[1];
    char* command = argv[2];

    BaseProcessor* proc = NULL;
    argv_t kwargs;

    if (strcmp(command, COMMAND_GEOMETRIC_TRANSFORMATION_ROTATE_RESERVE) == 0) {
        if (argc < 4) {
            cerr << ERROR_MESS_INVALID_ARGUMENTS << endl;
            return -1;
        }
        proc = new ConservativeRotation(pathToImage);
        kwargs["theta"] = argv[3];
    }
    else if (strcmp(command, COMMAND_GEOMETRIC_TRANSFORMATION_ROTATE_NONRESERVE) == 0) {
        if (argc < 4) {
            cerr << ERROR_MESS_INVALID_ARGUMENTS << endl;
            return -1;
        }
        proc = new NonConservativeRotation(pathToImage);
        kwargs["theta"] = argv[3];
    }
    else if (strcmp(command, COMMAND_GEOMETRIC_TRANSFORMATION_SCALE) == 0) {
        if (argc < 5) {
            cerr << ERROR_MESS_INVALID_ARGUMENTS << endl;
            return -1;
        }
        proc = new Scaling(pathToImage);
        kwargs["c_x"] = argv[3];
        kwargs["c_y"] = argv[4];
    }
    else {
        cerr << ERROR_MESS_INVALID_COMMANDS << endl;
        return -1;
    }
    proc->execute(kwargs);
    delete proc;
    return 0;
}
