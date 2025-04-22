//Priority Queue -  FIFO data structure that serves elements with highest priority first
//                  before serving elements with lower priority. 
//                  Each element is declared with a priority key and value

#include <iostream> //used to allow input/output
#include <queue> //used when instantiating queues
#include <iomanip> //used to allow for fixed, and setprecision methods
using namespace std;

//********************
//FUNCTIONS
//********************

struct GPA {
    int priority;
    double gpa;
    GPA(int _priority, double _gpa) : priority(_priority), gpa(_gpa){}
    friend ostream& operator<<(ostream& os, const GPA& gpa);
};

ostream& operator<<(ostream& os, const GPA& gpa){
    os << gpa.priority << " - " << gpa.gpa;
    return os;
}

struct GPACompare{
    bool operator()(const GPA& Y1, const GPA& Y2) const{
        double Y1Sum = Y1.priority + Y1.gpa;
        double Y2Sum = Y2.priority + Y2.gpa;
        return Y1Sum > Y2Sum;
    }
};

//********************
//MAIN
//********************

int main() {

    //ordered priority queue WTF?!
    
    priority_queue<GPA, vector<GPA>, GPACompare> gpa;
    GPA Y1(3, 3.5);
    GPA Y2(2, 2.0);
    GPA Y3(1, 1.5);
    GPA Y4(5, 4.0);
    GPA Y5(4, 3.8);

    gpa.push(Y1);
    gpa.push(Y2);
    gpa.push(Y3);
    gpa.push(Y4);
    gpa.push(Y5);

    while(!gpa.empty()){
        GPA topGPA = gpa.top();
        cout << fixed << setprecision(1) << topGPA << endl;
        gpa.pop();
    }

    //standard priority queue
    /*
    priority_queue<double> gpa;

    gpa.push(3.0);
    gpa.push(2.5);
    gpa.push(4.0);
    gpa.push(1.5);
    gpa.push(2.0);

    while(!gpa.empty()) {
        double t = gpa.top();
        cout << "Ordered Queue: " << fixed << setprecision(1) << t << endl;
        gpa.pop();
    }
        */

    return 0;
}