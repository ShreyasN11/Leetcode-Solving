# @param {Integer[]} nums
# @return {Integer}
def majority_element(nums)
    count = Hash.new(0)
    n = nums.length

    for i in 0...n
        count[nums[i]] +=1
        if count[nums[i]] > n/2
            return nums[i]
        end    
    end

end