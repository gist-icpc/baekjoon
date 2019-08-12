#include <cstdio>

int students[101] = {999999}, order[101] = {999999};

int main(){
	int n, m, good, num = 0, history = 0;
	
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++){
		scanf("%d", &good);
		
		if(num == n && !students[good]){
			int toDel = 0;
			for(int i = 1; i <= 100; i++){
				if(students[i]){
					if(students[toDel] > students[i] || (students[toDel] == students[i] && order[toDel] > order[i])){
						toDel = i;
					}
				}
			}
			
			students[toDel] = 0;
			order[toDel] = 0;
			
			students[good]++;
			order[good] = ++history;
		}
		
		else{
			if(!students[good]){
				history++;
				order[good] = history;
				num++;
			}
			students[good]++;
		}
	}
	
	for(int i = 1; i <= 100; i++)
		if(students[i]) printf("%d ", i);
}
