# @param {Integer[]} nums
# @return {Integer}
def remove_duplicates(nums)
    n = nums.length
    k = 1
    count = 1
    for i in 1...n
        if nums[i] != nums[i-1]
            nums[k] = nums[i]
            k +=1
            count = 1
        elsif count == 1
            nums[k] = nums[i]
            k+=1
            count = 2
        end   
    end
    return k
                 
end