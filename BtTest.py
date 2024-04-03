class BehaviorNode:
    def __init__(self, name):
        self.name = name
        self.result = False

    def execute(self):
        pass

class ActionNode(BehaviorNode):
    def __init__(self, name, action):
        super().__init__(name)
        self.action = action

    def execute(self):
        self.action()

class SequenceNode(BehaviorNode):
    def __init__(self, name, children):
        super().__init__(name)
        self.children = children

    def execute(self):
        for child in self.children:
            child.execute()
            if child.result == False:
                return False
        return True

def action1():
    print("Action 1")

def action2():
    print("Action 2")

def action3():
    print("Action 3")

root = SequenceNode("Root", [
    ActionNode("Action 1", action1),
    ActionNode("Action 2", action2),
    ActionNode("Action 3", action3)
])

root.execute()