#include "common.h"
#include "BaseProcessor.h"
#include "GeometricTransformProcessor.h"

int main(int argc, char* argv[]) {
    if (argc < 3) {
        cerr << ERROR_MESS_INVALID_ARGUMENTS << endl;
        return -1;
    }

    char* pathToImage = argv[1];
    char* command = argv[2];

    BaseProcessor* proc = new GeometricTransformProcessor(pathToImage);
    argv_t kwargs;

    if (strcmp(command, COMMAND_GEOMETRIC_TRANSFORMATION_ROTATE_RESERVE) == 0) {
    }
    else if (strcmp(command, COMMAND_GEOMETRIC_TRANSFORMATION_ROTATE_NONRESERVE) == 0) {
    }
    else if (strcmp(command, COMMAND_GEOMETRIC_TRANSFORMATION_SCALE) == 0) {
    }
    else {
        cerr << ERROR_MESS_INVALID_COMMANDS << endl;
        return -1;
    }
    proc->execute(kwargs);
    delete proc;
    return 0;
}
