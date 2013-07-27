#include <iostream>

using namespace std;

int data[6] = {0};

int notdfs(int remsum)
{
	if(remsum == 0)
		return 1;

    for(int i=0; i<6; ++i)
    {
        if(data[i] > 0 && remsum - 6 + i >= 0)
        {
			--data[i];
            if(notdfs(remsum - 6 + i))
                return 1;
        }
    }
    return 0;
}

int main(void)
{
	int cases = 1;
    while(1)
    {
        cin>>data[5]>>data[4]>>data[3]>>data[2]>>data[1]>>data[0];
		if(data[0]+data[1]+data[2]+data[3]+data[4]+data[5] == 0)
			break;
		cout<<"Collection #"<<cases++<<":"<<endl;
		int sum = data[0]*6+data[1]*5+data[2]*4+data[3]*3+data[4]*2+data[5];
		if(sum%2)
		{
			cout<<"Can't be divided."<<endl<<endl;
		}
		else
		{
			if(notdfs(sum/2))
				cout<<"Can be divided."<<endl<<endl;
			else
				cout<<"Can't be divided."<<endl<<endl;
		}
    }
	
	return 0;
}