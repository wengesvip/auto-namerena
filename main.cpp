#include "autotest.h"

int main(){
	prefix="�ĸ�F",suffix="",team_name="�û���"; 
	updatePos();
	cout<<"\n������ǰ׺���������Ժ�Enter��:";
	cin>>prefix;
	cout<<"\n����ս����:";
	cin>>team_name;
	cout<<"\n������͵ȼ����ȼ����ڵ�����͵ȼ��ı��������򲻱�����:";
	cin>>threshold_level;
	cout<<"\n������ʹ������������ڵ�����ʹ����ı��������򲻱�����:";
	cin>>threshold_score;
	cout<<"\n";
	cout<<"���ո����ʼ���ٰ��ո��ֹͣ����[Q]�����ݴ������������ţ���[W]�����ݰ�Χ���������ţ���[E]�����ݸ�����߼�������������"<<"\n"; 
	while(1){
		if(KEY_DOWN(VK_SPACE)){
			while(KEY_DOWN(VK_SPACE))Sleep(10);
			Start();
		}
		if(KEY_DOWN('Q')){
			while(KEY_DOWN('Q'))Sleep(10);
			Print(0);
		}
		if(KEY_DOWN('W')){
			while(KEY_DOWN('W'))Sleep(10);
			Print(1);
		}
		if(KEY_DOWN('E')){
			while(KEY_DOWN('E'))Sleep(10);
			Print(2);
		}
		Sleep(10);
	}
	return 0;
}
