//Begin page Go_to_positionA
void go_to_positionA(){
    target[0]=0.47;
    if (myZRState[0] < target[0]){
	    api.setPositionTarget(positionA);
	}
	else {
	   step++;
	}
}
//End page Go_to_positionA
//Begin page Go_to_positionC
void go_to_positionC(){
    target[0]=0.03;
    if (myZRState[0] > target[0]){
	    api.setPositionTarget(positionC);
	}
	else {
	   step++;
	}
}
//End page Go_to_positionC
//Begin page main
//Declare any variables shared between functions here
float positionA[3];
float positionC[3];
float myZRState[12];
float target[3];
int step;

void init(){
	//This function is called once when your code is first loaded.

	//IMPORTANT: make sure to set any variables that need an initial value.
	//Do not assume variables will be set to 0 automatically!
	
	positionA[0]=0.5;
	positionA[1]=0.0;
	positionA[2]=0.0;
	
	positionC[0]=0.0;
	positionC[1]=1.0;
	positionC[2]=0.0;
}

void loop(){
	//This function is called once per second.  Use it to control the satellite.
	
	api.getMyZRState(myZRState);
	if (step==0){
	    go_to_positionA();
	}
	else if (step==1){
	    go_to_positionC();
	}
	else {
	    step=0;
	}
}

//End page main
