//
// File:   LeeMain.cc
// Author: appiah
//
// Created on 4 January 1980, 00:05
//

#include <iostream>
#include <cstdlib>
#include <string>
#include <map>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <ctime>
#include <set>
#include <cmath>
#include <stdio.h>
#include <iomanip>
#include <iterator>
#include <sys/unistd.h>
#include <time.h>
#include <sys/ioctl.h>
#include <sched.h>
#include <pthread.h>
#include <fstream>
#include <unistd.h>
#include "LEEType.h"
#include "IsImplies.h"

using namespace std;

namespace{
    
    action a="buy", a1="sell", a2="sold", a3="trade";
    
    interest ia="sell_pc", ia1="buy_pc";
    rank r="rank_9";
    location loc="tottenham", loc1="London";
    temporal temp="Sat 12/09/2019 12:00pm";
    
    std::string go;
    IsImplies is;
    
    std::string enterStarts(){
        std::string start="go-leelus";
        return start;
    }
    
    std::string enterContinues(){
        std::string con="go-leelus";
        return con;
    }
    
    inline std::ostream& italic(std::ostream& stream){
        stream << "\033[3m";
        return stream;
    }
    
    inline std::ostream& reset(std::ostream& stream){
        stream << "\033[00m";
        return stream;
    }
    
    inline std::ostream& bold(std::ostream& stream){
        stream << "\033[1m";
        return stream;
    }
    
    inline std::ostream& underline(std::ostream& stream){
        stream << "\033[4m";
        return stream;
    }
    
    inline std::ostream& blink(std::ostream& stream){
        stream << "\033[5m";
        return stream;
    }
    
    inline std::ostream& dark(std::ostream& stream){
        stream << "\033[2m";
        return stream;
    }
    
    template <int code> inline
    std::ostream& color(std::ostream& stream){
        char command[12];
        snprintf(command, sizeof(command), "\033[38;5;%dm", code);
        stream<< command;
        return stream;
    }
    
    template <int r, int g, int b> inline
    std::ostream& color(std::ostream& stream){
        char command[20];
        snprintf(command, sizeof(command), "\033[38;2;%d;%d;%dm", r, g, b);
        stream<< command;
        return stream;
    }
    
    void setLEEValues(){
        
        
        Enactage en1;
        en1.setAction(a);
        en1.setLocation(loc);
        en1.setTemporal(temp);
        
        Enact en2;
        en2.setInterests(ia, ia1);
        en2.setRank(r);
        
        is.setEnact1(en1, en2);
        
        enactEL EL(en1, en2);
        is.setEnact(EL);
        Enactage EA(a, loc, temp);
        is.setInterestAct1(EA, a);
        
        is.setEnact1(EA, en2);
        
        locationact LA(en1);
        
        is.setLocationAct1(loc, a);
        temporalrank TR(en2, EA);
        
        is.setTemporalRank1(temp, r);
        
    }
    
    void setContextLanguage(){
        cout<<endl<<"Structural Language Context(SLC)"<<endl;
        cout<<"(1)  Enact_E ---> Enact_L ::=";
        
        interest* iss=is.getEnact().getEnactmentL().getInterests();
        
        cout<<"Enact_E("<<is.getEnact().getEnactage().getAction();
        cout<<","<<is.getEnact().getEnactage().getLocation();
        cout<<","<<is.getEnact().getEnactage().getTemporal()<<")";
        cout<<" ---> "<<"Enact_L("<<iss[0]<<","<<iss[1]<<","<<is.getEnact().getEnactmentL().getRank()<<")"<<endl<<endl;
        //enterContinues();
       // sleep(1);
        cout<<"(2)  a_i ---> a_j ::= ";
        cout<<is.getEnact().getEnactage().getAction();
        cout<<"--->"<<iss[0]<<endl;
        // enterContinues();
       // sleep(1);
        cout<<endl<<"(3)  a_j ---> l ::= ";
        cout<<iss[0];
        cout<<" --->"<<is.getEnact().getEnactage().getLocation()<<endl;
        //enterContinues();
      //  sleep(1);
        cout<<endl<<"(4)  rank_i ---> t ::= ";
        cout<<is.getEnact().getEnactmentL().getRank();
        cout<<" --->"<<is.getEnact().getEnactage().getTemporal()<<endl;
        enterContinues();
       // sleep(1);
        cout<<"\nContextual Language for LEE"<<endl;
        cout<<"(i)The enact of business implies the enact of machinery, partonomy, interest, attention and more logic."<<endl;
        cout<<"(ii)The enact of business interest implies the enact of business action or event.";
        cout<<endl<<"(iii)The enact of business interest implies the enact of interest in a location.";
        cout<<endl<<"(iv)The enact rank of business interest implies the enact of the linear/temporal ordering of interest.";
        cout<<endl;
    }
    
    void setIsLanguage(){
       // sleep(1);
        cout<<"LEE is_Language";
       // sleep(1);
        cout<<"Contextual Language for LEE_is"<<endl;
        cout<<"(i) The enact of business is the enact of logic."<<endl;
        cout<<"(ii) The enact of business interest is the implication of business action. ";
        cout<<endl<<"(iii) The enact of business interest is in a location.";
        cout<<endl<<"(iv) The enact of business rank is based on temporal dimensions.";
    
        
    }
    
    
    void setLEEImplies(){
        cout<<endl<<"LEE Implies(LEE->)"<<endl;
        
        interest* iss=is.getEnact().getEnactmentL().getInterests();
        //sleep(1);
        cout<<"(1) Enact_E("<<is.getEnact().getEnactage().getAction();
        cout<<","<<is.getEnact().getEnactage().getLocation();
        cout<<","<<is.getEnact().getEnactage().getTemporal()<<")";
        cout<<" implies "<<"Enact_L("<<iss[0]<<","<<iss[1]<<","<<is.getEnact().getEnactmentL().getRank()<<")"<<endl<<endl;
        //enterContinues();
       // sleep(1);
        cout<<"(2)"<<is.getEnact().getEnactage().getAction();
        cout<<" implies "<<iss[0]<<endl;
        // enterContinues();
        //sleep(1);
        cout<<"(3)"<<iss[0];
        cout<<" implies "<<is.getEnact().getEnactage().getLocation()<<endl;
        //enterContinues();
        //sleep(1);
        cout<<"(4)"<<is.getEnact().getEnactmentL().getRank();
        cout<<" implies "<<is.getEnact().getEnactage().getTemporal()<<endl;
        enterContinues();
        //sleep(1);
        cout<<"Contextual Language for LEE Implications"<<endl;
        cout<<"(i)The enact of business is the enact of logic."<<endl;
        cout<<"(ii)The enact of business interest is the implication of business action.";
        cout<<endl<<"(iii)The enact of business interest is in a location.";
        cout<<endl<<"(iv)The enact of business rank is based on temporal dimensions.";
        
    }
    
    void setLEEImpliesLang(){
        cout<<endl<<"LEE Implies Language(LEE->)"<<endl;
        
        interest* iss=is.getEnact().getEnactmentL().getInterests();
       // sleep(1);
        cout<<"(1) Enact_E("<<is.getEnact().getEnactage().getAction();
        cout<<","<<is.getEnact().getEnactage().getLocation();
        cout<<","<<is.getEnact().getEnactage().getTemporal()<<")";
        cout<<" implies "<<"Enact_L("<<iss[0]<<","<<iss[1]<<","<<is.getEnact().getEnactmentL().getRank()<<")"<<endl<<endl;
        //enterContinues();
        cout<<"(2) Interest "<<is.getEnact().getEnactage().getAction();
        cout<<" implies Action "<<iss[0]<<endl;
        // enterContinues();
        //sleep(1);
        cout<<"(3) Interest "<<iss[0];
        cout<<" implies Action in Location "<<is.getEnact().getEnactage().getLocation()<<endl;
        //enterContinues();
        //sleep(1);
        cout<<"(4) Rank interest "<<is.getEnact().getEnactmentL().getRank();
        cout<<" implies Ordering in temporal dimension "<<is.getEnact().getEnactage().getTemporal()<<endl;
        enterContinues();
        //sleep(1);
        cout<<"Contextual Language for LEE Implications"<<endl;
        cout<<"(i)The enact of business is the enact of logic."<<endl;
        cout<<"(ii)The enact of business interest is the implication of business action.";
        cout<<endl<<"(iii)The enact of business interest is in a location.";
        cout<<endl<<"(iv)The enact of business rank is based on temporal dimensions.";
      
    }
    
    void setLEEDoubleArrow(){
        cout<<endl<<"LEE Double Arrow(LEE<==>)"<<endl;
        
        interest* iss=is.getEnact().getEnactmentL().getInterests();
        //sleep(1);
        cout<<"(1) Enact_E("<<is.getEnact().getEnactage().getAction();
        cout<<","<<is.getEnact().getEnactage().getLocation();
        cout<<","<<is.getEnact().getEnactage().getTemporal()<<")";
        cout<<" <==> "<<"Enact_L("<<iss[0]<<","<<iss[1]<<","<<is.getEnact().getEnactmentL().getRank()<<")"<<endl<<endl;
        //enterContinues();
        //sleep(1);
        cout<<"(2)"<<is.getEnact().getEnactage().getAction();
        cout<<" <==> "<<iss[0]<<endl;
        // enterContinues();
        //sleep(1);
        cout<<"(3)"<<iss[0];
        cout<<" <==> "<<is.getEnact().getEnactage().getLocation()<<endl;
        //enterContinues();
        //sleep(1);
        cout<<"(4)"<<is.getEnact().getEnactmentL().getRank();
        cout<<" <==> "<<is.getEnact().getEnactage().getTemporal()<<endl;
        enterContinues();
        
    }
    
    void setLEEStructLang(){
        cout<<endl<<"LEE Structural Language(LEEStruct Language)"<<endl;
        
        interest* iss=is.getEnact().getEnactmentL().getInterests();
        //sleep(1);
        cout<<"(1) Enact_E("<<is.getEnact().getEnactage().getAction();
        cout<<","<<is.getEnact().getEnactage().getLocation();
        cout<<","<<is.getEnact().getEnactage().getTemporal()<<")";
        cout<<" --> "<<"Enact_L("<<iss[0]<<","<<iss[1]<<","<<is.getEnact().getEnactmentL().getRank()<<")"<<endl<<endl;
       // sleep(1);
        cout<<"Reading\n::A run(r) of an agent in an engaged environment is thus a sequence of inter-logic environment of states and actions."<<endl;
        enterContinues();
        cout<<"(2)"<<is.getEnact().getEnactage().getAction();
        cout<<" --> "<<iss[0]<<endl;
        cout<<"Reading\n::A run of an agent by a sequence of inter-logic environment of states and actions in an engaged environment."<<endl;
        enterContinues();
       // sleep(1);
        cout<<"(3)"<<iss[0];
        cout<<" --> "<<is.getEnact().getEnactage().getLocation()<<endl;
        //sleep(1);
        cout<<"Reading\n::A run of an agent by sequence of inter-logic states and actions is localized in an engaged environment."<<endl;
        enterContinues();
        cout<<"(4)"<<is.getEnact().getEnactmentL().getRank();
        cout<<" --> "<<is.getEnact().getEnactage().getTemporal()<<endl;
        cout<<"Reading\n::A state is initially ranked in an engaged environment before choosing an action to execute (run in a specific time)."<<endl;
        
    }
    
    void setLEEAbbLanguage(){
        cout<<endl<<"LEE Abbreviation Language(LEEAbb Language)"<<endl;
        
        interest* iss=is.getEnact().getEnactmentL().getInterests();
       // sleep(1);
        cout<<"(1) Enact_E("<<is.getEnact().getEnactage().getAction();
        cout<<","<<is.getEnact().getEnactage().getLocation();
        cout<<","<<is.getEnact().getEnactage().getTemporal()<<")";
        cout<<" <==> "<<"Enact_L("<<iss[0]<<","<<iss[1]<<","<<is.getEnact().getEnactmentL().getRank()<<")"<<endl<<endl;
       // sleep(1);
        cout<<"Reading\n::An Enact_E will exist to be true implies Enact_L is true and  Enact_L existence is true implies Enact_E is true."<<endl;
        enterContinues();
        cout<<"(2)"<<is.getEnact().getEnactage().getAction();
        cout<<" <==> "<<iss[0]<<endl;
        cout<<"Reading\n::An interest a_i will exist to be true implies a_i is true and a hold to be true in existence implies a_i is existentially true."<<endl;
        enterContinues();
        cout<<"(3)"<<iss[0];
        cout<<" <==> "<<is.getEnact().getEnactage().getLocation()<<endl;
        //sleep(1);
        cout<<"Reading\n::An interest enaction, a_j is existentially true implies location exist to be true and location,l is very true in existence implies interest holding is truly in existence."<<endl;
        enterContinues();
        cout<<"(4)"<<is.getEnact().getEnactmentL().getRank();
        cout<<" <==> "<<is.getEnact().getEnactage().getTemporal()<<endl;
        cout<<"Reading\n::A rank for interest will exist true implies a chosen priority in time holds to be true."<<endl;
        
    }
    
    void setLEEDoubleArrowStruct(){
        cout<<endl<<"LEE Double Arrow Structures(LEE<-->)"<<endl;
        
        interest* iss=is.getEnact().getEnactmentL().getInterests();
       // sleep(1);
        cout<<"(1) (Enact_E("<<is.getEnact().getEnactage().getAction();
        cout<<","<<is.getEnact().getEnactage().getLocation();
        cout<<","<<is.getEnact().getEnactage().getTemporal()<<")";
        cout<<" --> "<<"Enact_L("<<iss[0]<<","<<iss[1]<<","<<is.getEnact().getEnactmentL().getRank()<<"))";
       // sleep(1);
        cout<<" and "<<" (Enact_L("<<iss[0]<<","<<iss[1]<<","<<is.getEnact().getEnactmentL().getRank()<<")";
        cout<<" --> "<<" Enact_E("<<is.getEnact().getEnactage().getAction();
        cout<<","<<is.getEnact().getEnactage().getLocation();
        cout<<","<<is.getEnact().getEnactage().getTemporal()<<"))"<<endl;
        sleep(1);

        cout<<"(2) ("<<is.getEnact().getEnactage().getAction();
        cout<<" --> "<<iss[0];
        cout<<") and ("<<iss[0];
        cout<<" --> "<<is.getEnact().getEnactage().getAction()<<")"<<endl;
      
        cout<<"(3) ("<<iss[0];
        cout<<" --> "<<is.getEnact().getEnactage().getLocation();
        cout<<") and ("<<is.getEnact().getEnactage().getLocation();
        cout<<" --> "<<iss[0]<<")"<<endl;
        
       
        cout<<"(4) ("<<is.getEnact().getEnactmentL().getRank();
        cout<<" ---> "<<is.getEnact().getEnactage().getTemporal();
        cout<<") and ("<<is.getEnact().getEnactage().getTemporal();
        cout<<" ---> "<<is.getEnact().getEnactmentL().getRank()<<")"<<endl;
      
        enterContinues();
        
    }
    
    
    void setLEEAbb(){
        cout<<endl<<"LEE Abbreviation(LEEAbb)::{";
        cout<<"LEE Implies are now abbreviated below:}"<<endl;
        
        interest* iss=is.getEnact().getEnactmentL().getInterests();
        
        //sleep(1);
        cout<<"(1) not "<<"Enact_E("<<is.getEnact().getEnactage().getAction();
        cout<<","<<is.getEnact().getEnactage().getLocation();
        cout<<","<<is.getEnact().getEnactage().getTemporal()<<")"<<endl;
        cout<<" or "<<"Enact_L("<<iss[0]<<","<<iss[1]<<","<<is.getEnact().getEnactmentL().getRank()<<")"<<endl<<endl;
        //enterContinues();
       // sleep(1);
        cout<<"(2) not "<<is.getEnact().getEnactage().getAction();
        cout<<" or "<<iss[0]<<endl;
        // enterContinues();
        sleep(1);
        cout<<"(3) not "<<iss[0];
        cout<<" or "<<is.getEnact().getEnactage().getLocation()<<endl;
        //enterContinues();
       // sleep(1);
        cout<<"(4) not "<<is.getEnact().getEnactmentL().getRank();
        cout<<" or "<<is.getEnact().getEnactage().getTemporal()<<endl;
        enterContinues();
        
        // cout<<endl;
    }
    
    
    void setLEELinearOrd(){
        cout<<endl<<"LEE Mapping Structure(LEE-Linear Ordering)"<<endl;
        
        interest* iss=is.getEnact().getEnactmentL().getInterests();
       // sleep(1);
        cout<<"Enact_E("<<is.getEnact().getEnactage().getAction();
        cout<<","<<is.getEnact().getEnactage().getLocation();
        cout<<","<<is.getEnact().getEnactage().getTemporal()<<")";
        cout<<" --> "<<"Enact_L("<<iss[0]<<","<<iss[1]<<","<<is.getEnact().getEnactmentL().getRank()<<")";
        cout<<" --> ";
        //enterContinues();
        cout<<is.getEnact().getEnactage().getAction();
        cout<<" --> "<<iss[0];
        // enterContinues();
        //sleep(1);
        cout<<" --> ";
        cout<<iss[0];
        cout<<" --> "<<is.getEnact().getEnactage().getLocation();
        //enterContinues();
       // sleep(1);
        cout<<" --> ";
        cout<<is.getEnact().getEnactmentL().getRank();
        cout<<" --> "<<is.getEnact().getEnactage().getTemporal()<<endl;
        enterContinues();
        
    }
    
    void setLEEConsequentRun(){
        cout<<endl<<"LEE Consequent Runs(LEE-runs)\n"<<endl;
        
        interest* iss=is.getEnact().getEnactmentL().getInterests();
        
        cout<<"D::Enact_E("<<is.getEnact().getEnactage().getAction();
        cout<<","<<is.getEnact().getEnactage().getLocation();
        cout<<","<<is.getEnact().getEnactage().getTemporal()<<")";
        cout<<" --> "<<"Enact_L("<<iss[0]<<","<<iss[1]<<","<<is.getEnact().getEnactmentL().getRank()<<")";
        cout<<" --> ";
        cout<<is.getEnact().getEnactage().getAction()<<endl;
        cout;
       // sleep(1);
        cout<<"Di::Enact_L("<<iss[0]<<","<<iss[1]<<","<<is.getEnact().getEnactmentL().getRank()<<")";
        cout<<" --> ";
        cout<<is.getEnact().getEnactage().getAction();
        cout<<" --> "<<iss[0]<<endl;
        cout;
       // sleep(1);
        cout<<"Dii::"<<iss[0];
        cout<<" --> ";
        cout<<iss[1];
        cout<<" --> "<<is.getEnact().getEnactage().getAction()<<endl;
        cout;
        //sleep(1);
        cout<<"Diii::"<<iss[0];
        cout<<" --> ";
        cout<<iss[1];
        cout<<" --> "<<is.getEnact().getEnactage().getLocation()<<endl;
        //sleep(1);
        cout<<"Div::"<<iss[1];
        cout<<" --> ";
        cout<<is.getEnact().getEnactage().getLocation();
        cout<<" --> "<<is.getEnact().getEnactmentL().getRank()<<endl;
        //sleep(1);
        cout<<"Dv::"<<is.getEnact().getEnactage().getLocation();
        cout<<" --> ";
        cout<<is.getEnact().getEnactmentL().getRank();
        cout<<" --> "<<is.getEnact().getEnactage().getTemporal()<<endl;
        
    }
    
    void setLEEComposite(){
        cout<<endl<<"LEE Propose Enactment (Enactment Formulas)\n"<<endl;
        
        cout<<"Propositional Constants::"<<"\nT and F\n";
        
        cout<<endl<<"Propositional Variables::"<<endl;
        
        interest* iss=is.getEnact().getEnactmentL().getInterests();
        //sleep(1);
        cout<<"Enact_E("<<is.getEnact().getEnactage().getAction();
        cout<<","<<is.getEnact().getEnactage().getLocation();
        cout<<","<<is.getEnact().getEnactage().getTemporal()<<")";
        cout<<" , "<<"Enact_L("<<iss[0]<<","<<iss[1]<<","<<is.getEnact().getEnactmentL().getRank()<<")";
        cout<<" , ";
        //enterContinues();
        cout<<is.getEnact().getEnactage().getAction();
        cout<<" , "<<iss[0];
        // enterContinues();
        //sleep(1);
        cout<<" , ";
        cout<<iss[0];
        cout<<" , "<<is.getEnact().getEnactage().getLocation();
        //enterContinues();
        //sleep(1);
        cout<<" , ";
        cout<<is.getEnact().getEnactmentL().getRank();
        cout<<" , "<<is.getEnact().getEnactage().getTemporal()<<endl;
        enterContinues();
        
        cout<<endl<<"Propositional Composites::"<<endl;
        cout<<endl<<"or-Composites"<<endl;
        //sleep(1);
        cout<<"(i) not Enact_E("<<is.getEnact().getEnactage().getAction();
        cout<<","<<is.getEnact().getEnactage().getLocation();
        cout<<","<<is.getEnact().getEnactage().getTemporal()<<")";
        cout<<" or "<<"Enact_L("<<iss[0]<<","<<iss[1]<<","<<is.getEnact().getEnactmentL().getRank()<<")"<<endl;
        //sleep(1);
        cout<<"(ii) not "<<is.getEnact().getEnactage().getAction();
        cout<<" or "<<iss[0]<<endl;
        //sleep(1);
        cout<<"(iii) not "<<iss[0];
        cout<<" or "<<is.getEnact().getEnactage().getLocation()<<endl;
        //sleep(1);
        cout<<"(iv) not "<<is.getEnact().getEnactmentL().getRank();
        cout<<" or "<<is.getEnact().getEnactage().getTemporal()<<endl;
        
        cout<<endl<<"not-Composites"<<endl;
        //sleep(1);
        //sleep(1);
        cout<<"(i) not "<<"Enact_E("<<is.getEnact().getEnactage().getAction();
        cout<<","<<is.getEnact().getEnactage().getLocation();
        cout<<","<<is.getEnact().getEnactage().getTemporal()<<")"<<endl;
        //sleep(1);
        cout<<"(ii) not "<<is.getEnact().getEnactage().getAction()<<endl;
       // sleep(1);
        cout<<"(iii) not "<<iss[0]<<endl;
        cout<<"(iv) not "<<is.getEnact().getEnactmentL().getRank()<<endl;
        
        cout<<endl<<"and-Composites"<<endl;
        
       // sleep(1);
        cout<<"(i)  (Enact_E("<<is.getEnact().getEnactage().getAction();
        cout<<","<<is.getEnact().getEnactage().getLocation();
        cout<<","<<is.getEnact().getEnactage().getTemporal()<<")";
        cout<<" --> "<<"Enact_L("<<iss[0]<<","<<iss[1]<<","<<is.getEnact().getEnactmentL().getRank()<<"))";
        cout<<" and "<<"(Enact_L("<<iss[0]<<","<<iss[1]<<","<<is.getEnact().getEnactmentL().getRank()<<")";
        cout<<" --> "<<"Enact_E("<<is.getEnact().getEnactage().getAction();
        cout<<","<<is.getEnact().getEnactage().getLocation();
        cout<<","<<is.getEnact().getEnactage().getTemporal()<<"))"<<endl;
        
        //sleep(1);
        cout<<"(ii) ("<<is.getEnact().getEnactage().getAction();
        cout<<" --> "<<iss[0];
        cout<<") and ("<<iss[0];
        cout<<" --> ";
        cout<<" "<<is.getEnact().getEnactage().getAction()<<")"<<endl;
        
        //sleep(1);
        cout<<"(iii) ("<<iss[0];
        cout<<" --> "<<is.getEnact().getEnactage().getLocation();
        cout<<" ) and ( "<<is.getEnact().getEnactage().getLocation();
        cout<<" --> "<<iss[0]<<")"<<endl;
        
        //sleep(1);
        cout<<"(iv) ("<<is.getEnact().getEnactmentL().getRank();
        cout<<" --> "<<is.getEnact().getEnactage().getTemporal();
        cout<<") and ( "<<is.getEnact().getEnactage().getTemporal();
        cout<<" --> "<<is.getEnact().getEnactmentL().getRank()<<")"<<endl;
        
        cout<<endl<<"implies-Composites"<<endl;
        //sleep(1);
        cout<<"(1) Enact_E("<<is.getEnact().getEnactage().getAction();
        cout<<","<<is.getEnact().getEnactage().getLocation();
        cout<<","<<is.getEnact().getEnactage().getTemporal()<<")";
        cout<<" --> "<<"Enact_L("<<iss[0]<<","<<iss[1]<<","<<is.getEnact().getEnactmentL().getRank()<<")"<<endl<<endl;
        //enterContinues();
        //sleep(1);
        cout<<"(2)"<<is.getEnact().getEnactage().getAction();
        cout<<" --> "<<iss[0]<<endl;
        // enterContinues();
       // sleep(1);
        cout<<"(3)"<<iss[0];
        cout<<" --> "<<is.getEnact().getEnactage().getLocation()<<endl;
        //enterContinues();
       // sleep(1);
        cout<<"(4)"<<is.getEnact().getEnactmentL().getRank();
        cout<<" --> "<<is.getEnact().getEnactage().getTemporal()<<endl;
        enterContinues();
        //sleep(1);
        
        
    }
}

int main(int argc, char** argv) {
    
    cout<<"LEE Run- (L)ogical (E)ngage (E)nactment Program"<<endl;
    cout<<endl;
    
    enterStarts();
    const char* data;
    cout<<"Program Location::"<<argv[0]<<endl;
    cout<<"Parameter passing argument list: -a <value> -l <value> -i <value1>:<value2> -t <value> -r <value> -n <value>";
    if(argc>1){
        a=argv[2];
        loc=argv[4];
        string s=argv[6];
        int c=s.find(":");
        string sv=s.substr(0, c);
        data=sv.c_str();
        ia=(char*)data;
        sv=s.substr(c+1, s.length()-1);
        data=sv.c_str();
        ia1=(char*)data;
        temp=argv[8];
        r=argv[10];
        cout<<"\nExecution Situation Name::"<<argv[12];
    }
    cout<<"\nParameters passed:: action="<<a<<" location="<<loc<<" temporal="<<temp;
    cout<<" interest(s)="<<ia<<" and "<<ia1<<endl<<endl;
    cout<<"LEE Language and Composites"<<endl;
    cout<<"Enactment Formalizations"<<endl;
    cout<<"Developed by: Frank Appiah"<<endl;
    
    enterContinues();
     //interpreter
    setLEEValues();
    enterContinues();
    cout<<"\nCalling context language function"<<endl;
    setContextLanguage();
    enterContinues();
    cout<<"\nCalling the LEE implication function"<<endl;
    setLEEImplies();
    enterContinues();
    cout<<"\nCalling the LEE implication language function"<<endl;
    setLEEImpliesLang();
    enterContinues();
    cout<<"\nCalling the LEE linear ordering function"<<endl;
    setLEELinearOrd();
    enterContinues();
    cout<<"\nCalling the LEE abbreviation function"<<endl;
   setLEEAbb();
    enterContinues();
   //interpretercont
    cout<<"\nCalling the LEE structure language function"<<endl;
    setLEEStructLang();
    enterContinues();
    cout<<"\nCalling the LEE abbreivation language function"<<endl;
    setLEEAbbLanguage();
    enterContinues();
    cout<<"\nCalling the LEE Double arrow function"<<endl;
    setLEEDoubleArrow();
    enterContinues();
    cout<<"\nCalling LEE dobule arrow structure function"<<endl;
    setLEEDoubleArrowStruct(); 
    enterContinues();
    cout<<"\nCalling the is_language function"<<endl;
    setIsLanguage(); //interpreterfinal
    enterContinues();
    cout<<"\nCalling LEE consequent function"<<endl;
    setLEEConsequentRun();
    enterContinues();
    cout<<"\nCalling the LEE composition function"<<endl;
    setLEEComposite();
    enterContinues();
    cout<<"\nSuccessful and exiting application"<<endl;
    return (EXIT_SUCCESS);
    
}

