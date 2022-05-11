var findMedianSortedArrays = function(nums1, nums2) {
    let m = nums1.length, n = nums2.length;
    let len = m+n;
    let ans;
    if(len%2){
        let mid = Math.trunc(len/2);
        let idx = 0;
        let mx=0, nx=0;
        while(idx<=mid){
            if(mx<m && nums1[mx]<=nums2[nx] || nx==n){
                if(idx==mid) ans = nums1[mx];
                mx++;
            }
            else{
                if(idx==mid && nx<n) ans = nums2[nx];
                nx++;
            }
            idx++;
        }
    }
    else{
        let mid = len/2 - 1;
        let idx = 0;
        let mx=0, nx=0;
        while(idx<mid){
            if(nums1[mx]<=nums2[nx] && mx<m || nx==n){
                mx++;
            }
            else{
                nx++;
            }
            idx++;
        }
        let a, b;
        if(nx==n || mx<m && nums1[mx]<nums2[nx]){
            a=nums1[mx];
            mx++;
        }else{
            a=nums2[nx];
            nx++;
        }
        
        if(nx==n || mx<m && nums1[mx]<nums2[nx]){
            b=nums1[mx];
            mx++;
        }else{
            b=nums2[nx];
            nx++;
        }
        ans = (a+b)/2;
    }
    return ans;
};
