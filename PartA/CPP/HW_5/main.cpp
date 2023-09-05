#include "Terminal.h"

int main() {
    try {
        run();
    }
    catch (exception& e){
        cout << e.what() << endl;
    }
    return 0;
}
