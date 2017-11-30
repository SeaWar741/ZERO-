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
//Begin page Go To Base
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
//End page Go To Base
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

//___________________________________
//Begin page Step 0: Pos A
void get_posA(){
    api.getMyZRState(myState);
        for (int i=0; i<3; i++){
            myPos[i]=myState[i];
        }
    	mathVecSubtract(vectorBetween,posA,myPos,3);
    	distance = mathVecMagnitude(vectorBetween,3);
    	if (distance >= 0.01){
    	    api.setPositionTarget(posA);
    	}
    	else if (distance < 0.01) {
    	    step++;
    	}
}
//End page Step 0: Pos A
//Begin page Step 1: Drill Pos A
void start_DrillingA(){
    api.getMyZRState(myState);
    game.getDrills(myState);
    game.getDrillError();
    api.setPositionTarget(posA);
        if (game.getDrillError() == false){
            if (game.getDrills(myState) <= 0){
                game.getDrillEnabled();
                api.setAttRateTarget(stop);
            }
            if (myState[11] >= stop[3]){
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
}
//End page Step 1: Drill Pos A
//Begin page Step 4: Pos B
void get_posB(){
    api.getMyZRState(myState);
        for (int i=0; i<3; i++){
            myPos[i]=myState[i];
        }
    	mathVecSubtract(vectorBetween,posB,myPos,3);
    	distance = mathVecMagnitude(vectorBetween,3);
    	if (distance > 0.01){
    	    api.setPositionTarget(posB);
    	}
    	else if (distance <= 0.01) {
    	    step++;
    	}
}
//End page Step 4: Pos B
//Begin page Step 5: Drill Pos B
void start_DrillingB(){
    api.getMyZRState(myState);
    game.getDrills(myState);
    game.getDrillError();
    api.setPositionTarget(posB);
        if (game.getDrillError() == false){
            if (game.getDrills(myState) <= 0){
                game.getDrillEnabled();
                api.setAttRateTarget(stop);
            }
            if (myState[11] >= stop[3]){
                game.startDrill();
                api.setAttRateTarget(rateTarget);
                game.checkSample();
            }
            if (game.checkSample()==true){
                game.pickupSample();
                game.getNumSamplesHeld();
            }
            if (game.getNumSamplesHeld()==2){
                api.setAttRateTarget(stop);
            }
            if ((myState[11] <= stop[2]) && (game.getNumSamplesHeld() == 2)){
                game.stopDrill();
                step++;
            }
        }
}
//End page Step 5: Drill Pos B
//Begin page Step 8: Pos C
void get_posC(){
    api.getMyZRState(myState);
        for (int i=0; i<3; i++){
            myPos[i]=myState[i];
        }
    	mathVecSubtract(vectorBetween,posC,myPos,3);
    	distance = mathVecMagnitude(vectorBetween,3);
    	if (distance > 0.01){
    	    api.setPositionTarget(posC);
    	}
    	else if (distance <= 0.01) {
    	    step++;
    	}
}
//End page Step 8: Pos C
//Begin page Step 9: Drill Pos C
void start_DrillingC(){
    api.getMyZRState(myState);
    game.getDrills(myState);
    game.getDrillError();
    api.setPositionTarget(posC);
        if (game.getDrillError() == false){
            if (game.getDrills(myState) <= 0){
                game.getDrillEnabled();
                api.setAttRateTarget(stop);
            }
            if (myState[11] >= stop[3]){
                game.startDrill();
                api.setAttRateTarget(rateTarget);
                game.checkSample();
            }
            if (game.checkSample()==true){
                game.pickupSample();
                game.getNumSamplesHeld();
            }
            if (game.getNumSamplesHeld()==2){
                api.setAttRateTarget(stop);
            }
            if ((myState[11] <= stop[3]) && (game.getNumSamplesHeld() == 2)){
                game.stopDrill();
                step++;
            }
        }
}
//End page Step 9: Drill Pos C

//____________________________________begining invert

//Begin page Step 0: Pos A
void get_posA2(){
    api.getMyZRState(myState);
        for (int i=0; i<3; i++){
            myPos[i]=myState[i];
        }
        mathVecSubtract(vectorBetween,posA,myPos,3);
        distance = mathVecMagnitude(vectorBetween,3);
        if (distance >= 0.01){
            api.setPositionTarget(posA2);
        }
        else if (distance < 0.01) {
            step++;
        }
}
//End page Step 0: Pos A
//Begin page Step 1: Drill Pos A
void start_DrillingA2(){
    api.getMyZRState(myState);
    game.getDrills(myState);
    game.getDrillError();
    api.setPositionTarget(posA2);
        if (game.getDrillError() == false){
            if (game.getDrills(myState) <= 0){
                game.getDrillEnabled();
                api.setAttRateTarget(stop);
            }
            if (myState[11] >= stop[3]){
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
}
//End page Step 1: Drill Pos A
//Begin page Step 4: Pos B
void get_posB2(){
    api.getMyZRState(myState);
        for (int i=0; i<3; i++){
            myPos[i]=myState[i];
        }
        mathVecSubtract(vectorBetween,posB,myPos,3);
        distance = mathVecMagnitude(vectorBetween,3);
        if (distance > 0.01){
            api.setPositionTarget(posB2);
        }
        else if (distance <= 0.01) {
            step++;
        }
}
//End page Step 4: Pos B
//Begin page Step 5: Drill Pos B
void start_DrillingB2(){
    api.getMyZRState(myState);
    game.getDrills(myState);
    game.getDrillError();
    api.setPositionTarget(posB2);
        if (game.getDrillError() == false){
            if (game.getDrills(myState) <= 0){
                game.getDrillEnabled();
                api.setAttRateTarget(stop);
            }
            if (myState[11] >= stop[3]){
                game.startDrill();
                api.setAttRateTarget(rateTarget);
                game.checkSample();
            }
            if (game.checkSample()==true){
                game.pickupSample();
                game.getNumSamplesHeld();
            }
            if (game.getNumSamplesHeld()==2){
                api.setAttRateTarget(stop);
            }
            if ((myState[11] <= stop[2]) && (game.getNumSamplesHeld() == 2)){
                game.stopDrill();
                step++;
            }
        }
}
//End page Step 5: Drill Pos B
//Begin page Step 8: Pos C
void get_posC2(){
    api.getMyZRState(myState);
        for (int i=0; i<3; i++){
            myPos[i]=myState[i];
        }
        mathVecSubtract(vectorBetween,posC,myPos,3);
        distance = mathVecMagnitude(vectorBetween,3);
        if (distance > 0.01){
            api.setPositionTarget(posC2);
        }
        else if (distance <= 0.01) {
            step++;
        }
}
//End page Step 8: Pos C
//Begin page Step 9: Drill Pos C
void start_DrillingC2(){
    api.getMyZRState(myState);
    game.getDrills(myState);
    game.getDrillError();
    api.setPositionTarget(posC2);
        if (game.getDrillError() == false){
            if (game.getDrills(myState) <= 0){
                game.getDrillEnabled();
                api.setAttRateTarget(stop);
            }
            if (myState[11] >= stop[3]){
                game.startDrill();
                api.setAttRateTarget(rateTarget);
                game.checkSample();
            }
            if (game.checkSample()==true){
                game.pickupSample();
                game.getNumSamplesHeld();
            }
            if (game.getNumSamplesHeld()==2){
                api.setAttRateTarget(stop);
            }
            if ((myState[11] <= stop[3]) && (game.getNumSamplesHeld() == 2)){
                game.stopDrill();
                step++;
            }
        }
}
//End page Step 9: Drill Pos C

//____________________________________end invert

//Begin page main

//Declaration of variable type
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

//invert variables
float posA2[3];
float posB2[3];
float posC2[3];


//Variable declaration
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

    //__________________________
    posA2[0]=-0.35;
    posA2[1]=-0.35;
    posA2[2]=0.0;
    
    posB2[0]=0.35;
    posB2[1]=-0.35;
    posB2[2]=0.0;
    
    posC2[0]=-0.15;
    posC2[1]=-0.15;
    posC2[2]=0.0;
    //__________________________
	
	basePosR[0]=0.1;
	basePosR[1]=0.1;
	basePosR[2]=0.0;
	
	basePosL[0]=-0.1;
	basePosL[1]=0.1;
	basePosL[2]=0.0;

	rateTarget[0]=0.0;
	rateTarget[1]=0.0;
	rateTarget[2]=36*PI/180;
	
	stop[0]=0.0;
	stop[1]=0.0;
	stop[2]=0.0;
	
	step = 0;
}

void loop(){
	//This function is called once per second.  Use it to control the satellite.
    api.getMyZRState(myState);
    if (myState[0]>0)
        {
        //Blue
         switch (step) {
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
            break;
                case 4:
                    get_posB();
                    break;
                case 5:
                    start_DrillingB();
                    break;
                case 6:
                    goto_BaseL();
                    break;
                case 7:
                    at_Base();
                    break;
                        /*case 8:
                            get_posC();
                            break;
                        case 9:
                            start_DrillingC();
                            break;
                        case 10:
                            goto_Base();
                            break;
                        case 11:
                            at_Base();
                            break;*/
            }
            DEBUG(("Step = %d",step));
        }	
    else 
        {
        //RED
         switch (step) {
        case 0:
            get_posA2();
            break;
        case 1:
            start_DrillingA2();
            break;
        case 2:
            goto_BaseR();
            break;
        case 3:
            at_Base();
            break;
                case 4:
                    get_posB2();
                    break;
                case 5:
                    start_DrillingB2();
                    break;
                case 6:
                    goto_BaseL();
                    break;
                case 7:
                    at_Base();
                    break;
            }
            DEBUG(("Step = %d",step));
        }
}

//End page main
