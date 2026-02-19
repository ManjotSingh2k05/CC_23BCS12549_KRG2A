class Solution {
public:
long long mod=1e9+7;
    int nthMagicalNumber(int n, int a, int b) {
        long long right=(1ll*n*min(a,b));
    long long left=min(a,b);
    long long lcm=(a*b)/std::gcd(a,b);
    long long result=0;
    while(left<right)
    {
        long long mid=left+(right-left)/2;
        if(mid%a==0||mid%b==0)
        {
            int mulA=mid/a;
            int mulB=mid/b;
            int mulLCM=mid/lcm;
            int total_mul=mulA+mulB-mulLCM;
            if(total_mul==n) {
                result=mid;
                break;
            }
            else
            {
                if(total_mul<n) left=mid+1;
                else right=mid-1;
            }
        }
        else
        {
            int mulA=mid/a;
            int mulB=mid/b;
            int mulLCM=mid/lcm;
            int total_mul=mulA+mulB-mulLCM;
            if(total_mul<n) left=mid+1;
            else right=mid-1;
        }
    }
    if(left==right) result=left;
    return result%mod;
    }
};
