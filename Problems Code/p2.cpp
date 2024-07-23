/*
  • In this problem we assumed that the activities will be sorted according to their finish time,
    So the first activity always be selected.

  • The Greedy algorithm (choice) here is to always pick the next activity that has the smallest finish time
    and it's start time is more than or equal to finish time of the previously selected activity.

  • Time complexity for this problem will be O(N).

  • N -> Total Number Of Activities.
*/

#include <iostream>
#include <vector>
using namespace std;

// Global variable to keep track the maximum number of the activities.
int maxNumOfActivities = 0;

// class to store the set of activities.
class Activitiy
{
    private:
        int startTime;
        int finishTime;
    public:
        Activitiy (int, int);
        void setStartTime (int);
        void setFinishTim (int);
        int getStartTime ();
        int getFinishTim ();
};

// Function to get the set of maximum number of activities that can be done by a single person, one at a time.
void maxActivities (Activitiy [], int);

//Function to print the set of maximum number of activities that can be done by a single person, one at a time.
void printMaxActivities (vector<int>, Activitiy []);

int main()
{
    int totalNumberOfActivities = 11;
    Activitiy arr[] = { {1, 4}, {3, 5}, {0, 6}, {5, 7}, {3, 8}, {5, 9}, {6, 10}, {8, 11}, {8, 12}, {2, 13}, {12, 14} };

    cout << "Input:" << endl;
    cout << totalNumberOfActivities << endl;
    cout << "{1, 4}, {3, 5}, {0, 6}, {5, 7}, {3, 8}, {5, 9}, {6, 10}, {8, 11}, {8, 12}, {2, 13}, {12, 14}" << endl;
	maxActivities(arr, totalNumberOfActivities);
	cout << endl;

	return 0;
}

Activitiy::Activitiy (int sTime, int eTime)
{
    startTime = sTime;
    finishTime = eTime;
}
void Activitiy::setStartTime (int sTime)
{
    startTime = sTime;
}
void Activitiy::setFinishTim (int eTime)
{
    finishTime = eTime;
}
int Activitiy::getStartTime ()
{
    return startTime;
}
int Activitiy::getFinishTim ()
{
    return finishTime ;
}

void maxActivities(Activitiy setOfActivities[], int totalNumberOfActivities)
{
    // To store the set of maximum number of activities.
    vector<int> maxSetOfActivities;

    // To keep track the current selected activity.
    int selectedActivity = 0;


    // As we mentioned above, that we assumed that the activities will be sorted according to their finish time,
    // So the first activity always be selected and increase the maximum number of activities by one.
    maxSetOfActivities.push_back(selectedActivity);
    maxNumOfActivities++;

	// Then we will check for the rest of the activities.
	for (int i = 1; i < totalNumberOfActivities; i++)
    {
		// If this activity has start time greater than or equal to the
		// finish time of previously selected activity, then we will select it and increase the maximum number of activities by one.
		if (setOfActivities[i].getStartTime() >= setOfActivities[selectedActivity].getFinishTim())
        {
            maxNumOfActivities++;
			selectedActivity = i;
			maxSetOfActivities.push_back(selectedActivity);
		}
	}

	// To print the set of maximum number of activities.
	printMaxActivities (maxSetOfActivities, setOfActivities);
}

void printMaxActivities (vector<int> maxSetOfActivities, Activitiy setOfActivities[])
{
    cout << "Output:" << endl;
    cout << maxNumOfActivities << endl;

    for (int i = 0; i < maxSetOfActivities.size(); i++)
    {
        cout << "{" << setOfActivities[maxSetOfActivities[i]].getStartTime() << ", " << setOfActivities[maxSetOfActivities[i]].getFinishTim()  << "}";
        if (i < maxSetOfActivities.size() - 1)
        {
            cout << ", ";
        }
    }
}
