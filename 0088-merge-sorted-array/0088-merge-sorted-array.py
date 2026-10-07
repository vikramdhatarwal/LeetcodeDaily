class Solution:
    def merge(self, nums1: list[int], m: int, nums2: list[int], n: int) -> None:
        p1=m-1
        p2=n-1
        i=m+n-1
        while (p2>=0 and p1>=0):
            if(nums1[p1]<=nums2[p2]):
                nums1[i]=nums2[p2]
                p2-=1
                i-=1
            else:
                nums1[p1],nums1[i]=nums1[i],nums1[p1]
                p1-=1
                i-=1
        while p2>=0 :
            nums1[i]=nums2[p2]
            i-=1
            p2-=1
        