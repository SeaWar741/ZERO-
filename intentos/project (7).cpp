//Begin page At Base
void at_Base(){
game.atBaseStation();
game.getNumSamplesHeld();
    if (game.atBaseStation()==true){
        game.dropSample(0);
        game.dropSample(1);
        game.dropSample(2);
    }
    if (game.getNumSamplesHeld()==0){
        step++;
    }
}
//End page At Base
//Begin page Azul 0: Pos A
void get_posA(){
api.getMyZRState(myState);
    for (int i=0; i<3; i++){
        myPos[i]=myState[i];
    }
    if ((myState[0] < posA[0]) && (myState[1] < posA[1])) {
        mathVecSubtract(vectorBetween,posA,myPos,3);
    	distance = mathVecMagnitude(vectorBetween,3);
    	if (distance > 0.15){
    	    api.setForces(vectorBetween);
    	}
    	else {
    	    api.setPositionTarget(posA);
    	}
    }
    /*else if ((myState[0] > posA[0]) && (myState[1] > posA[1])){
        api.setPositionTarget(posA);
    }*/
    else {
        step++;
    }
}
//End page Azul 0: Pos A
//Begin page Azul 1: Drill A
void start_DrillingA(){
    api.getMyZRState(myState);
    game.getDrills(myState);
    api.setPositionTarget(posA);
    if (game.getDrills(myState) <= 0){
        game.getDrillEnabled();
    }
    if (myState[11] >= stop[2]){
        game.startDrill();
        api.setAttRateTarget(rateTarget);
        game.checkSample();
    }
    if (game.checkSample()==true){
        game.pickupSample();
        game.getNumSamplesHeld();
    }
    if (game.getNumSamplesHeld() == 2){
        api.setAttRateTarget(stop);
    }
    if ((myState[11] <= 0.1) && (game.getNumSamplesHeld() == 2)){
        game.stopDrill();
        step++;
    }
}

//End page Azul 1: Drill A
//Begin page Go to Base L
void goto_BaseL(){
api.getMyZRState(myState);
    for (int l=0; l<3; l++){
        myPos[l]=myState[l];
    }
	mathVecSubtract(vectorBetween,basePosL,myPos,3);
	distance = mathVecMagnitude(vectorBetween,3);
	if (distance > 0.01){
	    api.setPositionTarget(basePosL);
	}
	else if (distance <= 0.01) {
	    step++;
	}
}
//End page Go to Base L
//Begin page Go to Base R
void goto_BaseR(){
api.getMyZRState(myState);
    for (int l=0; l<3; l++){
        myPos[l]=myState[l];
    }
	mathVecSubtract(vectorBetween,basePosR,myPos,3);
	distance = mathVecMagnitude(vectorBetween,3);
	if (distance > 0.01){
	    api.setPositionTarget(basePosR);
	}
	else if (distance <= 0.01) {
	    step++;
	}
}
//End page Go to Base R
//Begin page Rojo 0: Pos D
void get_posD(){
api.getMyZRState(myState);
    for (int i=0; i<3; i++){
        myPos[i]=myState[i];
    }
    if ((myState[0] > posD[0]) && (myState[1] > posD[1])) {
        mathVecSubtract(vectorBetween,posD,myPos,3);
    	distance = mathVecMagnitude(vectorBetween,3);
    	if (distance > 0.15){
    	    api.setForces(vectorBetween);
    	}
    	else {
    	    api.setPositionTarget(posD);
    	}
    }
    else if ((myState[0] < posD[0]) && (myState[1] < posD[1])){
        api.setPositionTarget(posD);
    }
    else {
        step++;
    }
}
//End page Rojo 0: Pos D
//Begin page Rojo 1: Drill D
void start_DrillingD(){
    api.getMyZRState(myState);
    game.getDrills(myState);
    game.getDrillError();
    api.setPositionTarget(posD);
    if (game.getDrillError() == false){
        if (game.getDrills(myState) <= 0){
            game.getDrillEnabled();
        }
        if ((myState[11] >= stop[2])||(myState[11] <= stop[2])){
            game.startDrill();
            api.setAttRateTarget(rateTarget);
            game.checkSample();
        }
        if (game.checkSample()==true){
            game.pickupSample();
            game.getNumSamplesHeld();
        }
        if (game.getNumSamplesHeld() == 2){
            api.setAttRateTarget(stop);
        }
        if ((myState[11] <= stop[2]) && (game.getNumSamplesHeld() == 2)){
            game.stopDrill();
            step++;
        }
    }
    else {
        game.stopDrill();
    }
}
//End page Rojo 1: Drill D
//Begin page main
//Declare any variables shared between functions here
float myState[12];
float myPos[3];
float vectorBetween[3];
float posA[3];
float posD[3];
float distance;
float stop[3];
float rateTarget[3];
int step;
float basePosR[3];
float basePosL[3];

void init(){
	//This function is called once when your code is first loaded.

	//IMPORTANT: make sure to set any variables that need an initial value.
	//Do not assume variables will be set to 0 automatically!
	posA[0]=0.35;
	posA[1]=0.35;
	posA[2]=0.0;
	
	posD[0]=-0.35;
	posD[1]=-0.35;
	posD[2]=0.0;
	
	basePosR[0]=0.1;
	basePosR[1]=0.1;
	basePosR[2]=0.0;
	
	basePosL[0]=-0.1;
	basePosL[1]=0.1;
	basePosL[2]=0.0;
	
	stop[0]=0.0;
	stop[1]=0.0;
	stop[2]=0.0;
	
    rateTarget[0]=0.0;
	rateTarget[1]=0.0;
	rateTarget[2]=35*PI/180;  
	
	step=0;
}

void loop(){
	//This function is called once per second.  Use it to control the satellite.
	api.getMyZRState(myState);
    if (myState[1] > 0){
        switch (step){
            case 0:
                get_posA();
                break;
            case 1:
                start_DrillingA();
                break;
            case 2:
                goto_BaseR();
                break;
            case 3: 
                at_Base();
        }
    }
    else {
        switch (step){
            case 0:
                get_posD();
                break;
            case 1:
                start_DrillingD();
                break;
        }
    }
    DEBUG(("step = %d",step));
}

//End page main
