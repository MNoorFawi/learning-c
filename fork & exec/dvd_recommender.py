## Our Recommender System Script (dvd_recommender.py)
import sys
from pprint import pprint
from py2neo import Graph

cid = sys.argv[1:]

#authenticate("localhost:7474", "username", "password") 
g = Graph("http://localhost:7474/db/data/", password = "password")

def cf_recommender(graph, cid, nearest_neighbors, num_recommendations):

    query = """
           MATCH (c1:Customer)-[:RENTED]->(f:Film)<-[:RENTED]-(c2:Customer)
           WHERE c1 <> c2 AND c1.customerID = $cid
           WITH c1, c2, COUNT(DISTINCT f) as intersection
           
           MATCH (c:Customer)-[:RENTED]->(f:Film)
           WHERE c in [c1, c2]
           WITH c1, c2, intersection, COUNT(DISTINCT f) as union
           WITH c1, c2, intersection, union, 
                (intersection * 1.0 / union) as jaccard_index
           ORDER BY jaccard_index DESC, c2.customerID
           WITH c1, COLLECT(c2)[0..$k] as neighbors
           WHERE SIZE(neighbors) = $k                                              
           UNWIND neighbors as neighbor
           WITH c1, neighbor
           MATCH (neighbor)-[:RENTED]->(f:Film)         
           WHERE not (c1)-[:RENTED]->(f)                        
           WITH c1, f, COUNT(DISTINCT neighbor) as countnns
           ORDER BY c1.customerID, countnns DESC                            
           RETURN c1.customerID as customer, 
                  COLLECT(f.Title)[0..$n] as recommendations      
           """

    recommendations = {}
    # cid = [str(c) for c in cid]
    for c in cid:
        for i in graph.run(query, cid = c, k = nearest_neighbors, n = num_recommendations).data():
            recommendations[i["customer"]] = i["recommendations"]
    return recommendations

pprint(cf_recommender(g, cid, 25, 5))
