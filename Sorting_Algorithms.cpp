/**Sadia Ansari
Used Textbook for this homework.*/

/**#Include statements go here.*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;
/**Global variables*/

/**1.Create a function to read in the integer data from the supplied files.*/

int num_comparisons = 0;
int num_exchanges = 0;

 int* read_file(char * name_of_file)
 {
    ifstream current_file;

    current_file.open(name_of_file);

    if(!current_file.is_open())
    {
        cout << "This file does not exist. Try again" << name_of_file << endl;

    }
    string temp;
    string content_of_file="";
    while(current_file.peek()!=EOF)
    {
        current_file>>temp;
        content_of_file += temp + " ";
    }
    current_file.clear();
    current_file.close();

    vector<string> content_vector;
    temp= "";
    for( int i = 0; i < content_of_file.length();i++)
    {
        if (content_of_file[i] == ' ')
        {
            content_vector.push_back(temp);
            temp = "";
        }

        else
        {
            temp +=content_of_file[i];
        }
    }
    int * num = new int[content_vector.size()];
    for(int i=0; i< content_vector.size(); i++)
    {
        num[i]= atoi(content_vector[i].c_str());
    }
    return num;
}

/**2. Implement the five strategies.*/

/**Bubble Sort p443*/

void bubblesort(int A[], int n)
{
    //num_comparisons = (n - 1) * (n - 1);
    int i,j, temp;
    for(i = 1; i<n; i++)           /**Number of passes*/
    {
        for(j = 0; j<n-i; j++)     /**j varies from 0 to n-i.*/
        {
            num_comparisons++;
            if(A[j] > A[j+1])      /**Compare two numbers next to each other.*/
            {
                temp = A[j];        /**Swap A[j] with A[j+1].*/
                A[j] = A[j+1];
                A[j+1] = temp;
                num_exchanges++;
            }
        }
    }

}

/**Insertion Sort p447*/

void insertionsort(int A[], int n)
{

    int i,j, element;
    for(i = 1; i < n; i++)
    {
        element = A[i];                      /**Insert ith element in 0 to i-1 array*/
        j = i;
        while((j>0) && (A[j-1] > element))   /**Compare if A[j-1] is greater than element*/
        {
            A[j] = A[j-1];                   /**Shift elements*/
            num_exchanges++;
            j = j-1;
            num_comparisons++;
        }
        A[j] = element;
    }

}

/**Quick Sort p454-455*/

void swap(int &x, int &y)
{
    int temp;
    temp = x;
    x=y;
    y = temp;
}

int partition(int a[], int left, int right, int pivotIndex)
{
    int pivot = a[pivotIndex];
    do
    {
        while (a[left] < pivot)
        {left++;
        num_comparisons++;
        }
        num_comparisons++;
        while (a[right] > pivot)
        {right--;
        num_comparisons++;
        if (left < right && a[left] != a[right])
        {
            swap(a[left], a[right]);
            num_exchanges++;
        }
        else
        {
            return right;
        }
    }
    while (left < right);
    return right;
}
void quicksort(int a[], int left, int right)
{
    if (left < right)
    {
        int pivot = (left + right) / 2; // middle
        //num_comparisons++;
        int pivotNew = partition(a, left, right, pivot);
        //num_exchanges++;
        quicksort(a, left, pivotNew - 1);
        quicksort(a, pivotNew + 1, right);
    }
}

/**Shell Sort p460*/

void shellsort(int A[], int n)
{

    int temp, gap, i;
    int swapped;
    gap = n/2;
    do
    {
        do
        {
            swapped = 0;
            for(i = 0; i < n - gap; i++)
            num_comparisons++;
            {
                if(A[i] > A[i + gap])
                {
                    temp = A[i];
                    A[i] = A[i + gap];
                    A[i + gap] = temp;
                    swapped = 1;
                    num_exchanges++;
                }
            }
        }
        while(swapped == 1);
    }
    while((gap = gap/2) >= 1);

}


/** Merge Sort p467-468*/

void merge(int * A, int low, int high, int mid)
{

    int i, j, k, C[10000];
    i = low;
    k = low;                       /**Index for first part*/
    j = mid + 1;                    /**Index for second part*/
    while(i<= mid && j<= high) /**merge arrays A & B in array C*/
    {
        num_comparisons++;
        if(A[i] < A[j])
        {
            C[k] = A[i];
            num_exchanges++;

        }
        else
        {
            C[k] = A[j];
           exchanges++;
                   }
k++;
    }
    while (i <= mid)
    {
        C[k] = A[i];
       num_exchanges++;
        i++;
    }
    while (j <= high)
    {
        C[k] = A[j];
       num_exchanges++;

    }
    for (i = low; i < high; i++)
    {
        A[i] = C[j];
    }

}

void MergeSort(int *A, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid=(low+high)/2;
        MergeSort(A,low,mid);
        MergeSort(A,mid+1,high);
        merge(A, low, high, mid);
    }
    return;
}

/**3. Verify using small test sets(create them yourself that they are in fact sorting the data correctly.
Check out http://random.org/integers/ to help generate random numbers.*/
/**Execute the code and identify the number of comparisons and the number of exchanges.*/


/**NOTE: TABLE turned in via Sakai, and CODE turned in via GitHub!...Something about adding Putonti on GitHub????*/
/**NOTE: TEXTBOOK HAS A MISTAKE. Look up and fix!!!!*/
int main(int argc, const char * argv[])
{
    //int a[] = {5,2,3,4,1};
    //bubblesort(a, 5);
    //for (int i = 0; i < 5; i++) {
      //  cout << a[i] << endl;
    //}
    //num_comparisons = 0; num_exchanges = 0;
    //int b[] = {5,2,3,4,1};
    //insertionsort(b, 5);
    //for (int i = 0; i < 5; i++) {
      //  cout << b[i] << endl;
    //}
        num_comparisons = 0; num_exchanges = 0;
    int c[] = {2,3,5,4,1};
    quicksort(c, 1,5);
   for (int i = 0; i < 5; i++) {
       cout << c[i] << endl;
    }


    //int d[] = {5,2,3,4,1};
    //bubblesort(d, 5);
    //for (int i = 0; i < 5; i++) {
      //  cout << d[i] << endl;
    //}
    //int e[] = {5,2,3,4,1};
    //bubblesort(e, 5);
    //for (int i = 0; i < 5; i++) {
      //  cout << e[i] << endl;
    //}

    //read_file("NearlySorted.txt");
    bubblesort(read_file("NearlySorted.txt"),10000);
    cout << "comparisons: " << num_comparisons << "; exchanges: " << num_exchanges << endl;
    num_comparisons = 0; num_exchanges = 0;
    insertionsort(read_file("NearlySorted.txt"),10000);
    cout << "comparisons: " << num_comparisons << "; exchanges: " << num_exchanges << endl;
    num_comparisons = 0; num_exchanges = 0;
    (read_file("NearlySorted.txt"),10000);
    //shellsort(read_file("NearlySorted.txt"),10000);
    //merge(read_file("NearlySorted.txt"),10000);



    //bubblesort(read_file("FewUnique.txt"),10000);
    //insertionsort(read_file("FewUnique.txt"),10000);
    //partition(read_file("FewUnique.txt"),10000);
    //shellsort(read_file("FewUnique.txt"),10000);
    //merge(read_file("FewUnique.txt"),10000);


    //bubblesort(read_file("Random.txt"),10000);
    //insertionsort(read_file("Random.txt"),10000);
    //partition(read_file("Random.txt"),10000);
    //shellsort(read_file("Random.txt"),10000);
    //merge(read_file("Random.txt"),10000);


   // bubblesort(read_file("Reserved.txt"),10000);
    //insertionsort(read_file("Reserved.txt"),10000);
    //partition(read_file("Reserved.txt"),10000);
    //shellsort(read_file("Reserved.txt"),10000);
    //merge(read_file("Reserved.txt"),10000);






}
