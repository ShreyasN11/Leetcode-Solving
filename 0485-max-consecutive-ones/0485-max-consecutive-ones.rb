# @param {Integer[]} nums
# @return {Integer}
def find_max_consecutive_ones(nums)
    count = 0
    maxcount = 0
    n = nums.length
    for i in 0...n
        if nums[i] == 1
            count+=1
            maxcount = maxcount < count ? count : maxcount
        else 
            count = 0
        end
    end        
    return maxcount             
end