class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        result_map = {}
        for index, num in enumerate(nums):
            #if num in result_map.keys():  时间很长
            if num in result_map:   #时间很短
                return( [result_map[num] , index] )
            else:
                result_map[target-num] = index
