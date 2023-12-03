import rclpy
from rclpy.node import Node
from std_msgs.msg import String # replace with your message type

class MySubscriber(Node):
   def __init__(self):
       super().__init__('my_subscriber')
       self.subscription = self.create_subscription(
           String, # replace with your message type
           'forward_velocity_controller/commands', # replace with your topic name
           self.listener_callback,
           10)
       self.subscription

   def listener_callback(self, msg):
       self.get_logger().info('I heard: "%s"' % msg.data)

def main(args=None):
   rclpy.init(args=args)

   my_subscriber = MySubscriber()

   rclpy.spin(my_subscriber)

   my_subscriber.destroy_node()
   rclpy.shutdown()

if __name__ == '__main__':
   main()
