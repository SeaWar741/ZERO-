//Begin page main
//Declare any variables shared between functions here
float myState[12];
int step;
float myPos[3];
float posA[3];
float posB[3];
float posC[3];
float basePosR[3];
float basePosL[3];
float vectorBetween[3];
float distance;
float rateTarget[3];
float stop[3];
int counter;


float pos[12];
float forces[3];
float kp;


void init(){
	//This function is called once when your code is first loaded.

	//IMPORTANT: make sure to set any variables that need an initial value.
	//Do not assume variables will be set to 0 automatically!
	posA[0]=0.35;
	posA[1]=0.35;
	posA[2]=0.0;
	
	posB[0]=-0.35;
	posB[1]=0.35;
	posB[2]=0.0;
	
	posC[0]=0.15;
	posC[1]=0.15;
	posC[2]=0.0;
	
	step = 0;
		
	kp = 0.35;// coeficiente de velocidad. error contra velocidad, mayor más rápido
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

// void at_Base(){
// 	game.atBaseStation();
// 	game.getNumSamplesHeld();
// 	    if (game.atBaseStation()==true){
// 	        game.dropSample(0);
// 	        game.dropSample(1);
// 	        game.dropSample(2);
// 	    }
// 	    if (game.getNumSamplesHeld()==0){
// 	        step++;
// 	    }
// }

// void goto_BaseR(){
// 	api.getMyZRState(myState);
// 	    for (int l=0; l<3; l++){
// 	        myPos[l]=myState[l];
// 	    }
// 		mathVecSubtract(vectorBetween,basePosR,myPos,3);
// 		distance = mathVecMagnitude(vectorBetween,3);
// 		if (distance > 0.01){
// 		    api.setPositionTarget(basePosR);
// 		}
// 		else if (distance <= 0.01) {
// 		    step++;
// 		}
// }

// void goto_BaseL(){
// 	api.getMyZRState(myState);
// 	    for (int l=0; l<3; l++){
// 	        myPos[l]=myState[l];
// 	    }
// 		mathVecSubtract(vectorBetween,basePosL,myPos,3);
// 		distance = mathVecMagnitude(vectorBetween,3);
// 		if (distance > 0.01){
// 		    api.setPositionTarget(basePosL);
// 		}
// 		else if (distance <= 0.01) {
// 		    step++;
// 		}
// }

// void start_DrillingA(){
// 	api.getMyZRState(myState);
// 	game.getDrills(myState);
// 	game.getDrillError();
// 	api.setPositionTarget(posA);
// 	    if (game.getDrillError() == false){
// 	        if (game.getDrills(myState) <= 0){
// 	            game.getDrillEnabled();
// 	            api.setAttRateTarget(stop);
// 	        }
// 	        if (myState[11] >= stop[3]){
// 	            game.startDrill();
// 	            api.setAttRateTarget(rateTarget);
// 	            game.checkSample();
// 	        }
// 	        if (game.checkSample()==true){
// 	            game.pickupSample();
// 	            game.getNumSamplesHeld();
// 	        }
// 	        if (game.getNumSamplesHeld() == 2){
// 	            api.setAttRateTarget(stop);
// 	        }
// 	        if ((myState[11] <= stop[2]) && (game.getNumSamplesHeld() == 2)){
// 	            game.stopDrill();
// 	            step++;
// 	        }
// 	    }
// }

// void start_DrillingB(){
// 	api.getMyZRState(myState);
// 	game.getDrills(myState);
// 	game.getDrillError();
// 	api.setPositionTarget(posB);
// 	    if (game.getDrillError() == false){
// 	        if (game.getDrills(myState) <= 0){
// 	            game.getDrillEnabled();
// 	            api.setAttRateTarget(stop);
// 	        }
// 	        if (myState[11] >= stop[3]){
// 	            game.startDrill();
// 	            api.setAttRateTarget(rateTarget);
// 	            game.checkSample();
// 	        }
// 	        if (game.checkSample()==true){
// 	            game.pickupSample();
// 	            game.getNumSamplesHeld();
// 	        }
// 	        if (game.getNumSamplesHeld()==2){
// 	            api.setAttRateTarget(stop);
// 	        }
// 	        if ((myState[11] <= stop[2]) && (game.getNumSamplesHeld() == 2)){
// 	            game.stopDrill();
// 	            step++;
// 	        }
// 	    }
// }

// void start_DrillingC(){
// 	api.getMyZRState(myState);
// 	game.getDrills(myState);
// 	game.getDrillError();
// 	api.setPositionTarget(posC);
// 	    if (game.getDrillError() == false){
// 	        if (game.getDrills(myState) <= 0){
// 	            game.getDrillEnabled();
// 	            api.setAttRateTarget(stop);
// 	        }
// 	        if (myState[11] >= stop[3]){
// 	            game.startDrill();
// 	            api.setAttRateTarget(rateTarget);
// 	            game.checkSample();
// 	        }
// 	        if (game.checkSample()==true){
// 	            game.pickupSample();
// 	            game.getNumSamplesHeld();
// 	        }
// 	        if (game.getNumSamplesHeld()==2){
// 	            api.setAttRateTarget(stop);
// 	        }
// 	        if ((myState[11] <= stop[3]) && (game.getNumSamplesHeld() == 2)){
// 	            game.stopDrill();
// 	            step++;
// 	        }
// 	    }
// 	}


void loop(){
	//This function is called once per second.  Use it to control the satellite.
	switch (step) {
		// case 0:
		// 	step++;
		// 	break;
		case 0:
			goTo(posA);
			step++;
			break;
    	// case :
    	//     start_DrillingA();
    	//     break;
		case 1:
			goTo(posB);
			break;
    	// case 4:
    	//     at_Base();
    	//     break;
		// case 5:
		// 	goTo(posC);
		// 	break;
  //   	case 6:
  //   	    start_DrillingB();
  //   	    break;
  //   	case 7:
  //   	    goto_BaseL();
  //   	    break;
  //   	case 8:
  //   	    at_Base();
  //   	    break;
	}
	DEBUG(("Step = %d",step));
}