#include <iostream>
#include <algorithm>
#include <vector>


struct Job {
    int start, finish, profit;
};

int maxProfit(std::vector<Job> jobRequests) {
    // Sorting job request within increasing order
    std::sort(jobRequests.begin(), jobRequests.end(),
 [](Job &first, Job &last){
        return first.start < last.start;
    });

    int numberOfJobs = jobRequests.size();

    //BaseCase
    if(numberOfJobs == 0){
        return 0;
    }
    int maxProfitStore[numberOfJobs];

    //Iterate each job request

    for (int i = 0; i < numberOfJobs; i++)
    {
        // initialize current profit to 0
        maxProfitStore[i] = 0;

        // consider each `j` less than `i`
        for (int j = 0; j < i; j++)
        {
            if (jobRequests[j].finish <= jobRequests[i].start && maxProfitStore[i] < maxProfitStore[j]) {
                maxProfitStore[i] = maxProfitStore[j];
            }
        }

        // end the current task with i'th job
        maxProfitStore[i] += jobRequests[i].profit;
    }

    // return the maximum profit
    return *std::max_element(maxProfitStore, maxProfitStore + numberOfJobs);
}


int main()
{
   std:: vector<Job> jobRequest {
            { 1, 6, 60 },
            { 3, 9, 50 },
            { 5, 6, 30 },
            { 5, 3, 30 },
            { 3, 2, 20 },
            { 7, 7, 11 }
    };

   std:: cout << "The maximum profit is " << maxProfit(jobRequest);
    return 0;
}