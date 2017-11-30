//Begin page Do not move
void donot_Move(){
    /*target[0]=-0.25;
    target[1]=0.45;
	if ( (myState[0] > target[0]) || (myState[1] > target[1]) )   {
	    api.setPositionTarget(posA);
	}
	if ( (myState[0] < target[0]) || (myState[1] < target[1]) )  {
	    api.setPositionTarget(posA);
	}
	else {
	    step++;
	}*/
	api.setVelocityTarget(stop);
	step++;
}
//End page Do not move
//Begin page Paso 1. Analyzer
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
//End page Paso 1. Analyzer
//Begin page Paso 2. Pos A
void get_posA(){
    for (int i=0; i<3; i++){
               myPos[i]=myState[i];
    }
	   mathVecSubtract(vectorBetween,posA,myPos,3);
	   distance = mathVecMagnitude(vectorBetween,3);
	   if (distance>0.01){
	        api.setPositionTarget(posA);
	   }
	   else{
	       step++;
	   }

}
//End page Paso 2. Pos A
//Begin page Paso 3. Empieza Drill
void start_Drilling(){
    for (int i=0; i<3; i++){
               myPos[i]=myState[i];
    }
   
   
        if (myState <= myPos){
            game.getDrills(myState);
        }
        if (game.getDrills(myPos) <= 1){
            game.getDrillEnabled();
            api.setAttRateTarget(targetRate);
        }
        if (myState[11]>=targetRate[3]){
            //donot_Move();
            game.startDrill();
            //  try { game.startDrill(); } catch (int err ) { game.stopDrill(); api.setAttRateTarget(stop); 
            step = 1; //}
            game.checkSample();
        }
        if (game.checkSample()==true){
            game.pickupSample();
            game.getNumSamplesHeld();
        }
        if (game.getNumSamplesHeld()==2){
            game.stopDrill();
            api.setAttRateTarget(stop);
            step=4;
        }

/*
        if (myState <= myPos){
            game.getDrills(myState);
        }
        if (game.getDrills(myPos) <= 1){
            game.getDrillEnabled();
            api.setAttRateTarget(targetRate);
        }
        if (myState[11]>=targetRate[3]){
               
                bool bien;
                bien = game.startDrill();
                
            if ( not(bien) )
                {
                    game.stopDrill();
                    api.setAttRateTarget(stop);
                }
                else {
                    game.checkSample();
        
                if (game.checkSample()==true){
                    game.pickupSample();
                    game.getNumSamplesHeld();
                    }
          
                if (game.getNumSamplesHeld()==2){
                    game.stopDrill();
                    api.setAttRateTarget(stop);
                    }
                }

            } */
}

//
//End page Paso 3. Empieza Drill
//Begin page main
//Declare any variables shared between functions here
float myState[12];
float analyzerQ[3];
float analyzerW[3];
int step;
float targetRate[3];
float posA[3];
float myPos[3];
float vectorBetween[3];
float distance;
float target[3];
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
	
/*	switch ( step )
	    {
	        case 0 :
	            get_Analyzer();
	            break;
	        case 1 :
	            get_posA();
	            step++;
	            break;	    
	        case 2 :
	            donot_Move();
	    	    break;
	        case 3 :
	            start_Drilling();
	            step++;
	            break;
	        case 4 :
	            game.getConcentrations(concentrations);
	            if (concentrations[3] == -1)
	                {

	                    posA[0]=posA[0]+0.1;
	                    posA[1]=posA[1]+0.1;
	                    posA[2]=posA[2]+0.1;
	                    step=1;
                    }
	            if (concentrations[3] == -2)
	                {

	                	posA[0]=posA[0]+0.2;
	                    posA[1]=posA[1]+0.2;
	                    posA[2]=posA[2]+0.2;
	                    step=1;
	                    break;
	                }
	            if (concentrations[3] == 0)
	                {

	                	posA[0]=posA[0]+0.2;
	                    posA[1]=posA[1]+0.2;
	                    posA[2]=posA[2]+0.2;
	                    step=1;
	                 }
	            if (concentrations[3] > 0)
	                {

	                     DEBUG(("concentrations %f",concentrations));
	                     step = 5;
	                }
                break;
	        default:
	            posA[0]=0.0;
	            posA[1]=0.0;
	            posA[2]=0.0;
	            get_posA();
	            break;
	        
	    }
	    
	*/
	if (step==0){
	    get_Analyzer();
	    }
	else    if (step==1){
	            get_posA();
        	    }
	        else    if (step==2){
	                    donot_Move();
	                    }
	                else    if (step==3){
	                            start_Drilling();
	                            }
	                              else    if (step==4){
	                                posA[0]=0.0;
	                                posA[1]=0.0;
	                                posA[2]=0.0;
	                                get_posA();;
	                                }




DEBUG(("step # %d",step));
}

//End page main
