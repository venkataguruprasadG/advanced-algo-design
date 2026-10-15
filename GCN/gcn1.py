import torch
import torch.nn as nn
import torch.nn.functional as F
X = torch.tensor([
    [0.9, 0.1, 0.9],
    [0.8, 0.2, 0.8],
    [0.7, 0.2, 0.8],
    [0.2, 0.9, 0.2],
    [0.3, 0.8, 0.3],
    [0.9, 0.1, 1.0],
    [0.2, 0.8, 0.2],
    [0.8, 0.2, 0.9]
], dtype=torch.float32)
A = torch.tensor([
    [0, 1, 0, 0, 0, 1, 0, 0],
    [1, 0, 1, 0, 0, 0, 0, 0],
    [0, 1, 0, 1, 0, 0, 0, 0],
    [0, 0, 1, 0, 1, 0, 0, 0],
    [0, 0, 0, 1, 0, 1, 1, 0],
    [1, 0, 0, 0, 1, 0, 0, 1],
    [0, 0, 0, 0, 1, 0, 0, 1],
    [0, 0, 0, 0, 0, 1, 1, 0]
], dtype=torch.float32)
I = torch.eye(A.size(0))
A_tilde = A + I
degree = A_tilde.sum(dim=1)
D_inv_sqrt = torch.diag(degree.pow(-0.5))

A_hat = D_inv_sqrt @ A_tilde @ D_inv_sqrt
y = torch.tensor([1, 1, 1, 0, 0, 1, 0, 1])
class VanillaGCN(nn.Module):
    def __init__(self, input_dim, hidden_dim, output_dim):
        super().__init__()
        self.fc1 = nn.Linear(input_dim, hidden_dim)
        self.fc2 = nn.Linear(hidden_dim, output_dim)
    def forward(self, X, A_hat):
        # First graph convolution
        H = A_hat @ self.fc1(X)
        H = F.relu(H)
        # Second graph convolution
        H = A_hat @ self.fc2(H)
        H = F.relu(H)
        return H
torch.manual_seed(42)
model = VanillaGCN(
    input_dim=3,
    hidden_dim=8,
    output_dim=2
)
optimizer = torch.optim.Adam(model.parameters(), lr=0.01)
for epoch in range(201):
    model.train()
    optimizer.zero_grad()
    logits = model(X, A_hat)
    loss = F.cross_entropy(logits, y)
    loss.backward()
    optimizer.step()
    if epoch % 50 == 0:
        print(f"Epoch {epoch}, Loss: {loss.item():.4f}")
model.eval()
with torch.no_grad():
    logits = model(X, A_hat)
    predictions = logits.argmax(dim=1)
print("\nTraffic Congestion Predictions")
for i, prediction in enumerate(predictions):
    status = "Congested" if prediction.item() == 1 else "Non-congested"
    print(f"Road intersection {i}: {status}")

accuracy = (predictions == y).float().mean().item()
print(f"\nTraining-set accuracy: {accuracy:.2%}")
