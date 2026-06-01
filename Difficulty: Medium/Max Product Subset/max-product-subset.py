class Solution:
     def findMaxProduct(self, arr):
          # code here
          MOD = 10**9 + 7
          arr_l = len(arr)
          Ps = []
          Ne = []
          zeros = 0
          for i in range(arr_l):
               if arr[i] > 0:
                    Ps.append(arr[i])
               elif arr[i] < 0:
                    Ne.append(arr[i])
               else:
                    zeros += 1

          if zeros != 0 and len(Ps) == 0 and len(Ne) == 1:
               return 0
          if len(Ps) == 0 and len(Ne) == 1 and zeros == 0:
               return Ne[0]

          Ps_l = len(Ps)
          Ne_l = len(Ne)
          Ps_n = Ne_n = 1
          Ne_maxi = float('-inf')

          for i in range(Ne_l):
               Ne_maxi = max(Ne_maxi, Ne[i])
               Ne_n *= Ne[i]
          for j in range(Ps_l):
               Ps_n *= Ps[j]
          
          if Ne_l & 1:
               Ne_n //= Ne_maxi

          if Ps_l > 0 and Ne_l > 0:
               return int((Ps_n * Ne_n) % MOD)
          elif Ps_l > 0 and Ne_l == 0:
               return int(Ps_n % MOD)
          elif Ps_l == 0 and Ne_l > 0:
               return int(Ne_n % MOD)
          else:
               return 0