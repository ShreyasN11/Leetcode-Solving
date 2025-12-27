# @param {Integer[]} nums1
# @param {Integer} m
# @param {Integer[]} nums2
# @param {Integer} n
# @return {Void} Do not return anything, modify nums1 in-place instead.
def merge(nums1, m, nums2, n)
    res = []
    i=0 
    j=0
    while i<m && j<n
        if nums1[i] < nums2[j]
            res << nums1[i]
            i=i+1
        else
            res << nums2[j]
            j=j+1
        end
    end

    while i<m
        res << nums1[i]
        i = i+1
    end

    while j<n
        res << nums2[j]
        j = j+1
    end

    for i in 0...m+n
        nums1[i] = res[i]
    end    

end