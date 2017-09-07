/* Main program to run bpnet back propagation
 * Written by Louis Pearson and Daniel Ladner
 */

#include <iostream>
#include "bpnet.h"
using namespace std;

#define BPM_ITER	300000
float motorTotal = 180;

float sr = 80/motorTotal;
float sl = 100/motorTotal;
float dm = 90/motorTotal;

int main() {
	CBPNet bp;

	for (int i=0;i<BPM_ITER;i++) {
		//straight
bp.Train(31.00,22.00,sl,sr);
bp.Train(33.00,26.00,sl,sr);
bp.Train(32.00,28.00,sl,sr);
bp.Train(32.00,27.00,sl,sr);
bp.Train(32.00,32.00,sl,sr);
bp.Train(27.00,26.00,sl,sr);
bp.Train(29.00,26.00,sl,sr);
bp.Train(25.00,23.00,sl,sr);
bp.Train(25.00,23.00,sl,sr);
bp.Train(33.00,27.00,sl,sr);
bp.Train(33.00,31.00,sl,sr);
bp.Train(32.00,28.00,sl,sr);
bp.Train(32.00,30.00,sl,sr);
bp.Train(32.00,32.00,sl,sr);
bp.Train(33.00,32.00,sl,sr);
bp.Train(33.00,33.00,sl,sr);
bp.Train(31.00,27.00,sl,sr);
bp.Train(31.00,27.00,sl,sr);
bp.Train(31.00,27.00,sl,sr);
bp.Train(31.00,27.00,sl,sr);

bp.Train(0,0,sl,sr);
bp.Train(0,0,sl,sr);
bp.Train(0,0,sl,sr);
bp.Train(0,0,sl,sr);


//right turn
bp.Train(41.00,13.00,sl,dm);
bp.Train(41.00,13.00,sl,dm);
bp.Train(39.00,11.00,sl,dm);
bp.Train(38.00,15.00,sl,dm);
bp.Train(37.00,19.00,sl,dm);
bp.Train(36.00,20.00,sl,dm);
bp.Train(35.00,20.00,sl,dm);
bp.Train(36.00,15.00,sl,dm);
bp.Train(35.00,16.00,sl,dm);
bp.Train(36.00,15.00,sl,dm);
bp.Train(37.00,18.00,sl,dm);
bp.Train(35.00,21.00,sl,dm);
bp.Train(37.00,17.00,sl,dm);
bp.Train(38.00,15.00,sl,dm);
bp.Train(38.00,21.00,sl,dm);
bp.Train(36.00,18.00,sl,dm);
bp.Train(39.00,19.00,sl,dm);
bp.Train(40.00,19.00,sl,dm);
bp.Train(41.00,19.00,sl,dm);
bp.Train(41.00,19.00,sl,dm);


bp.Train(36, 26,sl,dm);
bp.Train(34, 24,sl,dm);
bp.Train(36, 25,sl,dm);
bp.Train(38, 20,sl,dm);
bp.Train(40, 23,sl,dm);
bp.Train(38, 23,sl,dm);
bp.Train(32, 19,sl,dm);
bp.Train(36, 26,sl,dm);
bp.Train(34, 24,sl,dm);
bp.Train(36, 25,sl,dm);
bp.Train(38, 20,sl,dm);
bp.Train(40, 23,sl,dm);
bp.Train(38, 23,sl,dm);
bp.Train(38, 7,sl,dm);
bp.Train(36, 6,sl,dm);
bp.Train(32, 4,sl,dm);
bp.Train(32, 12,sl,dm);
bp.Train(32, 4,sl,dm);


bp.Train(40.00,8.00,sl,dm);
bp.Train(40.00,9.00,sl,dm);








// left turn
bp.Train(14.00,29.00,dm,sr);
bp.Train(14.00,29.00,dm,sr);
bp.Train(14.00,29.00,dm,sr);
bp.Train(14.00,30.00,dm,sr);
bp.Train(14.00,29.00,dm,sr);
bp.Train(15.00,30.00,dm,sr);
bp.Train(14.00,25.00,dm,sr);
bp.Train(12.00,24.00,dm,sr);
bp.Train(13.00,27.00,dm,sr);
bp.Train(13.00,29.00,dm,sr);
bp.Train(12.00,23.00,dm,sr);
bp.Train(12.00,22.00,dm,sr);
bp.Train(16.00,28.00,dm,sr);
bp.Train(15.00,28.00,dm,sr);
bp.Train(15.00,29.00,dm,sr);

if(i%100000 == 0)cout<<(float)i/(float)BPM_ITER<<endl;







	}
	//tests:
	cout << "1, 0 = " << bp.Run(1,0)[0] <<","<< bp.Run(1,0)[1]<< endl;
	cout << "2, 0 = " << bp.Run(2,0)[0] <<","<< bp.Run(2,0)[1]<< endl;
	cout << "3, 0 = " << bp.Run(3,0)[0] <<","<< bp.Run(3,0)[1]<< endl;
	cout << "0, 1 = " << bp.Run(0,1)[0] <<","<< bp.Run(0,1)[1]<< endl;
	cout << "0, 2 = " << bp.Run(0,2)[0] <<","<< bp.Run(0,2)[1]<< endl;
	cout << "0, 3 = " << bp.Run(0,3)[0] <<","<< bp.Run(0,3)[1]<< endl;
	cout << "0, 0 = " << bp.Run(0,0)[0] <<","<< bp.Run(0,0)[1]<< endl;
	cout << "1, 1 = " << bp.Run(1,1)[0] <<","<< bp.Run(1,1)[1]<< endl;
	cout << "2, 2 = " << bp.Run(2,2)[0] <<","<< bp.Run(2,2)[1]<< endl;
	cout << "3, 3 = " << bp.Run(3,3)[0] <<","<< bp.Run(3,3)[1]<< endl<<endl;

	out = new float[2];

	cout << "1, 0 = " << run(1,0, out)[0] <<","<< run(1,0, out)[1]<< endl;
	cout << "2, 0 = " << run(2,0, out)[0] <<","<< run(2,0, out)[1]<< endl;
	cout << "3, 0 = " << run(3,0, out)[0] <<","<< run(3,0, out)[1]<< endl;
	cout << "0, 1 = " << run(0,1, out)[0] <<","<< run(0,1, out)[1]<< endl;
	cout << "0, 2 = " << run(0,2, out)[0] <<","<< run(0,2, out)[1]<< endl;
	cout << "0, 3 = " << run(0,3, out)[0] <<","<< run(0,3, out)[1]<< endl;
	cout << "0, 0 = " << run(0,0, out)[0] <<","<< run(0,0, out)[1]<< endl;
	cout << "1, 1 = " << run(1,1, out)[0] <<","<< run(1,1, out)[1]<< endl;
	cout << "2, 2 = " << run(2,2, out)[0] <<","<< run(2,2, out)[1]<< endl;
	cout << "3, 3 = " << run(3,3, out)[0] <<","<< run(3,3, out)[1]<< endl<<endl;
	cout<<endl<<endl;
	bp.printMatrix();
}

/*
Output

0,0 = 0.000941056
0,1 = 0.0244922
1,0 = 0.0249771
1,1 = 0.963577
Press any key to continue

*/