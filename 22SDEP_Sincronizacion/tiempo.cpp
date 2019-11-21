#include <iostream>
#include <ctime>
#include <sys/time.h>
using namespace std;

int main(){
	while(true){
		timeval t;
	    gettimeofday(&t, NULL);
	    time_t curr_time = time(NULL);
		tm* tm_local = localtime(&curr_time);

		char time_string[100];
		strftime(time_string, 50, "%T", tm_local);
		cout << time_string << "."  << t.tv_usec << endl;

	}
	return 0;
}