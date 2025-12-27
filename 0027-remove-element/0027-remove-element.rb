# @param {Integer[]} nums
# @param {Integer} val
# @return {Integer}
def remove_element(nums, val)
    n = nums.length
    k = 0
    for i in 0...n
        if nums[i] != val
            nums[k] = nums[i]
            k = k+1
        end
    end 

    return k       
end