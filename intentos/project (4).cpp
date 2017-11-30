//Begin page First Drill
void first_Drill(){
    target[0]=-0.25;                             //marca en x un objetivo
	if (myState[0] > target[0]){                // pide que se mueva a la posición A
	    api.setPositionTarget(posA);
	}
	if (myState[0] < target[0]){                //pide que se mantenga en la posición A
	    api.setPositionTarget(posA);
	}
	if (myState[0] <= posA[0]) {                //pide que empiece a rotar, consiga el numero de drills atual de la posA y active el drill
	    api.setAttRateTarget(targetRate);
	    game.getDrillEnabled();
	    game.getDrills(myState);
	}
	if ((myState[0] <= posA[0]) && (game.getDrills(myState) == 0)){ //si se cumplen las dos condiciones empieza drill y revisa si hay muestras
	    game.startDrill();
	    game.checkSample();
	}
    if (game.checkSample()==true){              //recoge la muestra y marca la cantidad conseguida
        game.pickupSample();
        game.getNumSamplesHeld();
    }
    if (game.getNumSamplesHeld() == 1){         //si tienes dos muestras deten tu rotación
        api.setAttRateTarget(stop);
    }
    if (myState[11] == stop[0]){                //si te detuviste apaga el drill
        game.stopDrill();
    }
}
//End page First Drill
//Begin page Get Analyzer
void get_Analyzer(){
    game.hasAnalyzer();
    if (myState[1]>0){
	    api.setPositionTarget(analyzerW);
	}
	else if (myState[1]<0) {
	    api.setPositionTarget(analyzerQ);
	}
	if ((game.hasAnalyzer()==1)||(game.hasAnalyzer()==2)){
	    step++;
	}
}
//End page Get Analyzer
//Begin page Move to Base Station
void move_Base(){
    target[0]=-0.03;
    if (myState[0]>target[0]){
        api.setPositionTarget(basePos);
    }
    if (myState[0]<target[0]){
        api.setPositionTarget(basePos);
    }
}
//End page Move to Base Station
//Begin page Second Drill
void second_Drill(){
    target[0]=0.25;                             //marca en x un objetivo
	if (myState[0] < target[0]){                // pide que se mueva a la posición A
	    api.setPositionTarget(posB);
	}
	if (myState[0] > target[0]){                //pide que se mantenga en la posición A
	    api.setPositionTarget(posB);
	}
	if (myState[0] >= posB[0]) {                //pide que empiece a rotar, consiga el numero de drills atual de la posA y active el drill
	    api.setAttRateTarget(targetRate);
	    game.getDrillEnabled();
	    game.getDrills(myState);
	}
	if ((myState[0] >= posB[0]) && (game.getDrills(myState) <= 1)){ //si se cumplen las dos condiciones empieza drill y revisa si hay muestras
	    game.startDrill();
	    game.checkSample();
	}
    if (game.checkSample()==true){              //recoge la muestra y marca la cantidad conseguida
        game.pickupSample();
        game.getNumSamplesHeld();
    }
    if (game.getNumSamplesHeld() == 2){         //si tienes dos muestras deten tu rotación
        api.setAttRateTarget(stop);
    }
    if (myState[11] == stop[0]){                //si te detuviste apaga el drill
        game.stopDrill();
    }
}
//End page Second Drill
//Begin page main
//Declare any variables shared between functions here
float myState[12];
float analyzerQ[3];
float analyzerW[3];
float posA[3];
float basePos[3];
float posB[3];
float target[3];
int step;
float targetRate[3];
float stop[3];
float concentrations[3];

void init(){
	//This function is called once when your code is first loaded.

	//IMPORTANT: make sure to set any variables that need an initial value.
	//Do not assume variables will be set to 0 automatically!
	analyzerQ[0]=0.30;
	analyzerQ[1]=-0.48;
	analyzerQ[2]=0.0;
	
	analyzerW[0]=-0.30;
	analyzerW[1]=0.48;
	analyzerW[2]=0.0;

	step=0;

	posA[0]=-0.25;
	posA[1]=0.45;
	posA[2]=0.0;
	basePos[0]=0.0;
	basePos[1]=0.0;
	basePos[2]=0.0;
	posB[0]=0.25;
	posB[1]=0.45;
	posB[2]=0.0;

	targetRate[0]=0.0;
	targetRate[1]=0.0;
	targetRate[2]=40*PI/180;
	stop[0]=0.0;
	stop[1]=0.0;
	stop[2]=0.0;
}

void loop(){
	//This function is called once per second.  Use it to control the satellite.
	api.getMyZRState(myState);
	
	if (step==0){
	    get_Analyzer();
	}
	else if (step==1){
	    first_Drill();
	}
	DEBUG(("step # %d",step));
}	
//End page main
