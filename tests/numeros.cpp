

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv){
    
	ofstream output; // stream for output file
	output.open(argv[1]);

	cout << argv [1] << endl;

	for (int i = 0; i<10 ; ++i){
		output << i;
	}

	output.close();

	return 1;

}
