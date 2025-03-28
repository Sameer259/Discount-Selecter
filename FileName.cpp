#include <iostream>
using namespace std;

int main() {
    int a, c, x, y, z;
    float ap, cp, d;

    // Input section
    cout << "Input the Price for Adult: ";
    cin >> ap;
    cout << "Input the Price for Child/Senior: ";
    cin >> cp;
    cout << "Input the counts of Adult and Child: ";
    cin >> a >> c;
    cout << "Input X Y for the Buy-X-get-Y: ";
    cin >> x >> y;
    cout << "Input D Z for group discount: ";
    cin >> d >> z;

    // Full price without discounts
    float fullPrice = (a * ap) + (c * cp);

    // Option A: Apply Buy-X-get-Y-free 
    int group = a / x;
    int remainingAdults = a - (group * x);       // Adults left after full groups
    int remainingChildren = c - (group * y);     // Children left after full groups
    if (remainingChildren < 0) remainingChildren = 0;  // Ensure no negative children count

    float priceA = (group * x * ap) + (remainingAdults * ap) + (remainingChildren * cp);

    // Option B: Apply D-percent-off if headcount meets or exceeds Z
    int totalPeople = a + c;
    int ghostCustomers = (totalPeople < z) ? z - totalPeople : 0;  // Ghosts needed to reach Z if necessary
    float priceB = (fullPrice + (ghostCustomers * cp)) * ((100 - d) / 100.0f);

    // Option C:  Buy-X-get-Y and D-percent-off for remaining people
    int adultsAfterDiscount = a - x;
    int childrenAfterDiscount = c - y;

    float buyXGetYCost = (x * ap);  // Cost for Buy-X-get-Y
    float remainingGroupCost = ((adultsAfterDiscount * ap) + (childrenAfterDiscount * cp)) * ((100 - d) / 100.0f);  // Apply D% discount on remaining

    float priceC = buyXGetYCost + remainingGroupCost;

    // Output each price for debugging
    /*cout << "remainingAdults: " << adultsAfterDiscount << endl;
    cout << "remainingChildren: " << childrenAfterDiscount << endl;
    cout << "priceA: " << priceA << endl;
    cout << "priceB: " << priceB << endl;
    cout << "priceC: " << priceC << endl;*/

    // Output the minimum payment among the calculated options with fixed decimal format

    float minimumPrice = min(priceA, min(priceB, priceC));
    cout << "The payment is: $" << minimumPrice;

    return 0;
}