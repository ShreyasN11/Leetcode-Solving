# @param {Integer[]} nums
# @return {Integer}
def remove_duplicates(nums)
    k = 1
    n = nums.length

    for i in 1...n
        if nums[i-1] != nums[i]
            nums[k] = nums[i]
            k+=1
        end
    end
    return k            
end