class Solution {
public:
    double new21Game(int N, int K, int W) {
        if(K==0||W+K-1<=N){
            return 1.0;
        }
        vector<double> prob(K+W,0);
        prob[0] = 1.0;
        
        if(K<W) {
            for(int i=1;i<=K;i++) {
                prob[i] = prob[i-1] + prob[i-1]/W;
            }
            for(int i=K+1;i<=W;i++) {
                prob[i] = prob[i-1] + prob[K-1]/W;
            }      
            
            for(int i=W+1;i<K+W;i++) {
                prob[i] = prob[i-1] + (prob[K-1] - prob[i-W-1])/W;
            }  
            
        } else {
            for(int i=1;i<=W;i++) {
                prob[i] = prob[i-1] + prob[i-1]/W;
            }
            for(int i=W+1;i<=K;i++) {
                prob[i] = prob[i-1] + (prob[i-1] - prob[i-W-1])/W;
            }
            for(int i=K+1;i<K+W;i++) {
                prob[i] = prob[i-1] + (prob[K-1] - prob[i-W-1])/W;
            }
        }

        return (prob[N]-prob[K-1])/(prob[K+W-1]-prob[K-1]);
    }
};