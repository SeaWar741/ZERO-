//Begin page main
//Declare any variables shared between functions here

float positionA[3];
float positionB[3];
int counter;

void init(){
	//This function is called once when your code is first loaded.

	//IMPORTANT: make sure to set any variables that need an initial value.
	//Do not assume variables will be set to 0 automatically!

	positionA[0]=0;
	positionA[1]=1;
	positionA[2]=0;
	
	positionB[0]=1;
	positionB[1]=0;
	positionB[2]=0;
	
	counter=0;
	
}

void loop(){
	//This function is called once per second.  Use it to control the satellite.
	api.setPositionTarget(positionA);
	if(counter>20){
	     api.setPositionTarget(positionB);
	}
	if(counter>40){
	     api.setPositionTarget(positionA);
	}
	counter++;
}

//End page main
