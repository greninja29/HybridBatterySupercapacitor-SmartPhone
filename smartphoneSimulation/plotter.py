import pandas as pd
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

# Read the CSV file into a DataFrame
df = pd.read_csv('results.csv')

# Extracting data for plotting
x = df[0]
y = df[1]
z = df[2]

# Create 3D plot
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

# Plot
ax.scatter(x, y, z, c='b', marker='o')

# Set labels and title
ax.set_xlabel('i')
ax.set_ylabel('j')
ax.set_zlabel('Paced Count')
ax.set_title('3D Plot of Paced Count against i and j')

plt.show()
