#include <iostream>

using namespace std;
class setmethod{
    int n, W;
    int *w, *p, **dp;
    int arr[2];
    
    void sortItems() {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (w[j] > w[j + 1]) {
                    swap(w[j], w[j + 1]);
                    swap(p[j], p[j + 1]);
                }
            }
        }
    }
    void solve(){
        for(int i=0;i<=W;i++){
            if(i=0){
                
            }
        }

    }
public:

void operations(){
    
}
};
int main(){
setmethod s;
s.operations();
return 0;

}