# @param {Integer[]} nums
# @return {Integer[]}
def smaller_numbers_than_current(nums)
    res = []
    n = nums.length

    for i in 0...n
        x = nums[i]
        count = 0;
        for j in 0...n
            if x > nums[j]
                count = count + 1
            end
        end
        res << count
    end
    return res            
end