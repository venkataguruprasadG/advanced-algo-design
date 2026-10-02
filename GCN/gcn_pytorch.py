import torch
import torch.nn as nn
import torch.nn.functional as F

class VanillaGCNLayer(nn.Module):
    def __init__(self, in_features, out_features):
        super(VanillaGCNLayer, self).__init__()
        # Learnable weight matrix W
        self.weight = nn.Parameter(torch.FloatTensor(in_features, out_features))
        nn.init.xavier_uniform_(self.weight)

    def forward(self, X, A):
        N = A.size(0)
        
        # Step 1: Add self-loops (A_tilde = A + I)
        A_tilde = A + torch.eye(N)
        
        # Step 2: Compute Degree Matrix D_tilde
        D_tilde_diag = torch.sum(A_tilde, dim=1)
        
        # Step 3: Compute D_tilde^(-1/2) for Symmetric Normalization
        D_tilde_inv_sqrt = torch.pow(D_tilde_diag, -0.5)
        D_tilde_inv_sqrt[torch.isinf(D_tilde_inv_sqrt)] = 0.0
        D_mat = torch.diag(D_tilde_inv_sqrt)
        
        # Step 4: Normalization (A_hat = D^(-1/2) * A_tilde * D^(-1/2))
        A_hat = torch.mm(torch.mm(D_mat, A_tilde), D_mat)
        
        # Step 5: Propagation (Output = A_hat * X * W)
        support = torch.mm(X, self.weight)
        output = torch.mm(A_hat, support)
        
        return output

class VanillaGCN(nn.Module):
    def __init__(self, input_dim, hidden_dim, output_dim):
        super(VanillaGCN, self).__init__()
        self.gcn1 = VanillaGCNLayer(input_dim, hidden_dim)
        self.gcn2 = VanillaGCNLayer(hidden_dim, output_dim)

    def forward(self, X, A):
        # Layer 1 + ReLU activation
        x = F.relu(self.gcn1(X, A))
        # Layer 2 (Output embeddings)
        x = self.gcn2(x, A)
        return x

# --- Execution Test ---
if __name__ == "__main__":
    # Sample Graph Adjacency Matrix (4 nodes)
    A = torch.tensor([
        [0., 1., 0., 0.],
        [1., 0., 1., 0.],
        [0., 1., 0., 1.],
        [0., 0., 1., 0.]
    ])
    
    # Input Feature Matrix X (4 nodes, 2 features each)
    X = torch.tensor([
        [1.0, 0.0],
        [0.5, 0.5],
        [0.2, 0.8],
        [0.0, 1.0]
    ])
    
    model = VanillaGCN(input_dim=2, hidden_dim=4, output_dim=2)
    output = model(X, A)
    
    print("Computed Node Embeddings:\n", output)