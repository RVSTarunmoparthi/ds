#include<iostream>
using namespace std;
class MergeSort
{
	private:
		int arr1[30],arr2[30];
	public:
		int n;
		void read();
		void display();
		void merge(int low,int mid,int high);
		void sort(int low,int high);
};
void MergeSort :: read()
{
	int i;
	cout<<"Enter number of Values:"<<endl;
	cin>>n;
	cout<<"Enter "<<n<<" values:"<<endl;
	for(i=0;i<n;i++)
	{
		cin>>arr1[i];
	}
}
void MergeSort :: display()
{
	int i;
	cout<<"The Values are:"<<endl;
	for(i=0;i<n;i++)
	{
		cout<<arr1[i]<<" ";
	}
	cout<<endl;
}
void MergeSort :: merge(int low,int mid,int high)
{
	int i,j,k;
	i = low;
	j = mid+1;
	k = 0;
	while((i<=mid) && (j<=high))
	{
		if(arr1[i] < arr1[j])
		{
			arr2[k] = arr1[i++];
		}
		else
		{
			arr2[k] = arr1[j++];
		}
		k++;
	}
	while(i<=mid)
	{
		arr2[k++] = arr1[i++];
	}
	while(j<=high)
	{
		arr2[k++] = arr1[j++];
	}
	for(i=low,j=0;i<=high;i++,j++)
	{
		arr1[i]=arr2[j];
	}
}
void MergeSort :: sort(int low,int high)
{
	if(low<high)
	{
		int mid = (low+high)/2;
		sort(low,mid);
		sort(mid+1,high);
		merge(low,mid,high);
	}
}
int main()
{
	int low,mid,high;
	MergeSort ms;
	ms.read();
	cout<<"Before Sorting,";
	ms.display();
	ms.sort(0,(ms.n)-1);
	cout<<"After Sorting,";
	ms.display();
	return 0;
}
