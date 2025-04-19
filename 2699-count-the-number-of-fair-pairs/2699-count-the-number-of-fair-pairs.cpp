const int N=256, mask=255, bshift=8;
int freq[N];

void radix_sort(int* nums, int n) {
    int* output = (int*)alloca(n * sizeof(int));  // buffer
        const unsigned biased=0x80000000;
            // Convert to biased form (signed to unsigned)
                unsigned M=0;
                    for (int i = 0; i < n; i++){
                            nums[i] ^= biased;
                                    M=max(M, (unsigned)nums[i]);
                                        }
                                            const int Mround = max(1, int(31-countl_zero(M)+bshift)/bshift);
                                                int* in=nums;
                                                    int* out=output;
                                                        bool swapped=0;

                                                            for (int round=0; round<Mround; round++) {
                                                                    const int shift=round*bshift;
                                                                            memset(freq, 0, sizeof(freq));

                                                                                    for (int i = 0; i < n; i++)
                                                                                                freq[(in[i] >> shift) & mask]++;

                                                                                                        partial_sum(freq, freq+N, freq);

                                                                                                                for (int i = n - 1; i >= 0; i--) {
                                                                                                                            int val = in[i];
                                                                                                                                        int x = (val >> shift) & mask;
                                                                                                                                                    out[--freq[x]] = val;
                                                                                                                                                            }

                                                                                                                                                                    swap(in, out);
                                                                                                                                                                            swapped = !swapped;
                                                                                                                                                                                }

                                                                                                                                                                                    // If needed, copy back
                                                                                                                                                                                        if (swapped)
                                                                                                                                                                                                memcpy(nums, in, n * sizeof(int));

                                                                                                                                                                                                    // Undo biasing
                                                                                                                                                                                                        for (int i = 0; i < n; i++)
                                                                                                                                                                                                                nums[i] ^= biased;
                                                                                                                                                                                                                }

                                                                                                                                                                                                                class Solution {
                                                                                                                                                                                                                public:
                                                                                                                                                                                                                    int n;
                                                                                                                                                                                                                        long long cnt(vector<int>& nums, int x){
                                                                                                                                                                                                                                int l=0, r=n-1;
                                                                                                                                                                                                                                        long long ans=0;
                                                                                                                                                                                                                                                while(l<r){
                                                                                                                                                                                                                                                            int s=nums[l]+nums[r];
                                                                                                                                                                                                                                                                        if (s<x) {
                                                                                                                                                                                                                                                                                        ans+=(r-l);
                                                                                                                                                                                                                                                                                                        l++;
                                                                                                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                                                                                                                else r--;
                                                                                                                                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                                                                                                                                return ans;
                                                                                                                                                                                                                                                                                                                                                    }

                                                                                                                                                                                                                                                                                                                                                        long long countFairPairs(vector<int>& nums, int lower, int upper) {
                                                                                                                                                                                                                                                                                                                                                                int* arr=nums.data();
                                                                                                                                                                                                                                                                                                                                                                        n=nums.size();
                                                                                                                                                                                                                                                                                                                                                                                radix_sort(arr, n);
                                                                                                                                                                                                                                                                                                                                                                                        return cnt(nums, upper+1)-cnt(nums, lower);
                                                                                                                                                                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                                                                                                                                                                            };