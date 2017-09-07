/* ========================================== *
 * Filename:	bpnet.h                       *
 * Author:		James Matthews.               *
 *											  *
 * Description:								  *
 * This is a tiny neural network that uses	  *
 * back propagation for weight adjustment.	  *
 * ========================================== */
/* Nerual network edited for 2 inputs and 2 outputs
 *
 * Editing done by Louis Pearson and Daniel Ladner.
 */

#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <iostream>

#define BP_LEARNING	(float)(0.5)	// The learning coefficient.
using namespace std;
class CBPNet {
	public:
		CBPNet();
		~CBPNet() {};
		CBPNet(int layers, int* neuronsInLayer);

		float Train(float, float, float, float);
		float* Run(float, float);

		void print();
		void printMatrix();

	private:
		float m_fWeights[3][4];		// Weights for the 3 neurons.

		float Sigmoid(float);		// The sigmoid function.

};
float* run(float i1, float i2, float* out);

CBPNet::CBPNet() {
	srand((unsigned)(time(NULL)));
	
	for (int i=0;i<3;i++) {
		for (int j=0;j<4;j++) {
			// For some reason, the Microsoft rand() function
			// generates a random integer. So, I divide by the
			// number by MAXINT/2, to get a num between 0 and 2,
			// the subtract one to get a num between -1 and 1.
			//m_fWeights[i][j] = (float)(rand())/(32767/2) - 1;
			m_fWeights[i][j] = (float)(rand())/(INT_MAX/2) - 1;
			//cout<<m_fWeights[i][j]<<" "<<endl;
		}
	}
	

}


float CBPNet::Train(float i1, float i2, float d, float d2) {
	// These are all the main variables used in the 
	// routine. Seems easier to group them all here.
	float net1, net2, i3, i4, out, out2;

	i1 /= 5;
	i2 /= 5;
	
	// Calculate the net values for the hidden layer neurons.
	net1 = 1 * m_fWeights[0][0] + i1 * m_fWeights[1][0] +
		  i2 * m_fWeights[2][0];
	net2 = 1 * m_fWeights[0][1] + i1 * m_fWeights[1][1] +
		  i2 * m_fWeights[2][1];

	// Use the hardlimiter function - the Sigmoid.
	i3 = Sigmoid(net1);
	i4 = Sigmoid(net2);

	// Now, calculate the net for the final output layer.
	//net1 and net2 now represent sums of inputs times weights 
	//for hidden layer to output layer
	net1 = 1 * m_fWeights[0][2] + i3 * m_fWeights[1][2] +
	   	  i4 * m_fWeights[2][2];
	out = Sigmoid(net1);

	net2 = 1 * m_fWeights[0][3] + i3 * m_fWeights[1][3] +
	   	  i4 * m_fWeights[2][3];
	out2 = Sigmoid(net2);

	// We have to calculate the deltas for the two layers.
	// Remember, we have to calculate the errors backwards
	// from the output layer to the hidden layer (thus the
	// name 'BACK-propagation').
	float deltas[4];
	
	deltas[3] = out2*(1-out2)*(d2 - out2);
	deltas[2] = out*(1-out)*(d-out);
	deltas[1] = i4*(1-i4)*(m_fWeights[2][2] * deltas[2] + m_fWeights[2][3] * deltas[3]);
	deltas[0] = i3*(1-i3)*(m_fWeights[1][2] * deltas[2] + m_fWeights[1][3] * deltas[3]);




	// Now, alter the weights accordingly.
	float v1 = i1, v2 = i2;
	for(int i=0;i<4;i++) {
		// Change the values for the output layer, if necessary.
		if (i == 2) {
			v1 = i3;
			v2 = i4;
		}
				
		m_fWeights[0][i] += BP_LEARNING*1*deltas[i];
		m_fWeights[1][i] += BP_LEARNING*v1*deltas[i];
		m_fWeights[2][i] += BP_LEARNING*v2*deltas[i];
	}

	return out;
}

float CBPNet::Sigmoid(float num) {
	return (float)(1/(1+exp(-num)));
}

float* CBPNet::Run(float i1, float i2) {
	// I just copied and pasted the code from the Train() function,
	// so see there for the necessary documentation.
	
	float net1, net2, i3, i4;
	float* out = new float[2];
	i1/=5;
	i2/=5;
	
	net1 = 1 * m_fWeights[0][0] + i1 * m_fWeights[1][0] +
		  i2 * m_fWeights[2][0];
	net2 = 1 * m_fWeights[0][1] + i1 * m_fWeights[1][1] +
		  i2 * m_fWeights[2][1];

	i3 = Sigmoid(net1);
	i4 = Sigmoid(net2);

	net1 = 1 * m_fWeights[0][2] + i3 * m_fWeights[1][2] +
	   	  i4 * m_fWeights[2][2];
	net2 = 1 * m_fWeights[0][3] + i3 * m_fWeights[1][3] +
	   	  i4 * m_fWeights[2][3];
	
	out[0] = Sigmoid(net1) * 180;
	out[1] = Sigmoid(net2) * 180;
	return out;
}

void CBPNet::print(){
		  cout<<"i0 h1: "<<m_fWeights[0][0]<<endl;
		  cout<<"i1 h1: "<<m_fWeights[1][0]<<endl;
		  cout<<"i2 h1: "<<m_fWeights[2][0]<<endl;
		  cout<<"i0 h2: "<<m_fWeights[0][1]<<endl;
		  cout<<"i1 h2: "<<m_fWeights[1][1]<<endl;
		  cout<<"i2 h2: "<<m_fWeights[2][1]<<endl;
		  cout<<"h0 o1: "<<m_fWeights[0][2]<<endl;
		  cout<<"h1 o1: "<<m_fWeights[1][2]<<endl;
		  cout<<"h2 o1: "<<m_fWeights[2][2]<<endl;
	}

void CBPNet::printMatrix(){
	//prints 2d array of weights to be moved to arduino
	cout<<"{";
	for(int row = 0;row < 3;row++){
		cout<<"{";
		for(int col = 0;col < 4;col++){
			cout<<m_fWeights[row][col];
			if(col!=4)cout<<",";
		}
		cout<<"}";
		if(row!=3)cout<<",";
		cout<<endl;
	}
	cout<<"};";
	cout<<endl;
}


float Sigmoid(float num) {
	return (float)(1/(1+exp(-num)));
}

float* out = new float[2];
float* run(float i1, float i2, float* out){
	float net1, net2, i3, i4;
	const float m_fWeights[3][4] = 
{{0.384649,-0.710097,2.07271,-1.25013,},
{-15.4408,16.5899,-2.08738,1.03143,},
{15.433,-16.5866,-1.8476,1.25634,},
};

	i1/=5;
	i2/=5;
	
	net1 = 1 * m_fWeights[0][0] + i1 * m_fWeights[1][0] +
		  i2 * m_fWeights[2][0];
	net2 = 1 * m_fWeights[0][1] + i1 * m_fWeights[1][1] +
		  i2 * m_fWeights[2][1];

	i3 = Sigmoid(net1);
	i4 = Sigmoid(net2);

	net1 = 1 * m_fWeights[0][2] + i3 * m_fWeights[1][2] +
	   	  i4 * m_fWeights[2][2];
	net2 = 1 * m_fWeights[0][3] + i3 * m_fWeights[1][3] +
	   	  i4 * m_fWeights[2][3];
	
	out[0] = Sigmoid(net1)*180;
	out[1] = Sigmoid(net2)*180;
	return out;
}
