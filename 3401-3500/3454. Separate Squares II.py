class Solution(object):
    def separateSquares(self, squares):
        # First Stage : Calculate Total Area
        # Take only unique y-coordinates
        y_coordinates = set()
        events = []
        # Transformed the problem from y-axis to x-axis
        for y,x,length in squares:
            # y1
            y_coordinates.add(y)
            # y2
            y_coordinates.add(y+length)
            # x1,Add Action,y1,y2
            events.append([x,1,y,y+length])
            # x2,Remove Action,y1,y2
            events.append([x+length,-1,y,y+length])
        
        # Sort them to be used in segment tree
        y_sorted = sorted(y_coordinates)

        y_map = {}
        # Keep track of indexes of y-coordinates in Segment Tree
        for i,y in enumerate(y_sorted):
            y_map[y]= i

        y_segment_tree = SegmentTree(y_sorted)
        events.sort()
        damn_area = 0
        prev_x = events[0][0]
        temp = []
        for x,event, y1, y2 in events:
            # y-range so far in our segment tree
            damn_area += (x-prev_x) * y_segment_tree.query()
            # Update(Add/Remove) the y-range in segment tree
            y_segment_tree.update(y_map[y1],y_map[y2],event)
            temp.append([x,damn_area])
            prev_x = x
        

        # Second Stage : calculate x-coordinate of half-area
        half_area =  damn_area/2.0
        prev_area,prev_x = 0,0

        # Can use binary search to make it more efficeint
        for x,area in temp:
            if area==half_area:
                return x
            
            if area > half_area:
                change_area = area-prev_area
                x_change = x-prev_x
                # Slope Formula for linear change in area b/w coordinates
                # x = (area-area1)*{(x2-x1)/(area2-area1)} + x1
                return (half_area-prev_area)*((1.0 * x_change)/change_area) + prev_x
            prev_area = area
            prev_x = x

# Special Segment Tree that makes sure overlapped ranges to be considered only once
class SegmentTree:
    def __init__(self,y):
        #1 Intentional reducing the size of Segment Tree
        self.n = len(y)-1
        self.y = y
        self.seg_tree = [0] * 4 * self.n
        self.lazy_tag = [0] * 4 * self.n

    def update(self,low,high,val):
        #2 Intentional high value reduced by 1 since our SegmentTree is smaller by 1
        self._update(0,0,self.n-1,low,high-1,val)

    def _update(self,node,left,right,low,high,val):
        if high < left or right < low:
            return
        
        left_child,right_child = 2*node+1,2*node+2
        #Complete Overlap it means complete Length is include in final sum
        if low<=left and right<=high:
            self.lazy_tag[node] += val
        else:
            mid = (left+right)>>1
            self._update(left_child,left,mid,low,high,val)
            self._update(right_child,mid+1,right,low,high,val)
        
        # Complete length has to be included in final sum
        if self.lazy_tag[node]>0:
            #3 Intentional right value incread by 1 to compensation of loss of size of 
            # SegmentTree
            self.seg_tree[node] = self.y[right+1] - self.y[left]
        elif left == right:
            self.seg_tree[node] = 0
        else:
            self.seg_tree[node] = self.seg_tree[left_child] + self.seg_tree[right_child]

    
    def query(self):
        return self.seg_tree[0]
