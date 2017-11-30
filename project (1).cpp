//Begin page main
//Declare any variables shared between functions here

float posA[3];
float pos[12];
float forces[3];
float kp;

void init(){
	//This function is called once when your code is first loaded.

	//IMPORTANT: make sure to set any variables that need an initial value.
	//Do not assume variables will be set to 0 automatically!
	posA[0] = 0.5;
	posA[1] = 0.5;
	posA[2] = 0;
	kp = 0.35;// coeficiente de velocidad. error contra velocidad, mayor más rápido
}


void loop(){
	//This function is called once per second.  Use it to control the satellite.
	goTo(posA);
	
}

void goTo(float* dest){
    api.getMyZRState(pos);
	int i = 0;
	for(i = 0; i < 3; i++){
	    float error = dest[i] - pos[i];
	    if(error < 0.01){
	        error = 0;
	    }
	    forces[i] = kp * error;
	}
	api.setVelocityTarget(forces);
}

//End page main
