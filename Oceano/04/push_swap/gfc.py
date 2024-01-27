#!/usr/bin/env python3

import re

def parse_ctags(tags):
    nodes = set()
    edges = set()

    with open(ctags_file, 'r') as file:
        for line in file:
            parts = line.strip().split('\t')
            if len(parts) >= 4:
                name, _, kind, file_path = parts[:4]
                nodes.add(name)
                if kind == 'f':  # Function tag
                    edges.add((file_path, name))

    return nodes, edges

def generate_dot(nodes, edges):
    dot_content = 'digraph flowchart {\n'
    for node in nodes:
        dot_content += f'    "{node}" [shape="box"];\n'
    for edge in edges:
        dot_content += f'    "{edge[0]}" -> "{edge[1]}";\n'
    dot_content += '}'
    return dot_content

def save_dot(dot_content, output_file='flowchart.dot'):
    with open(output_file, 'w') as file:
        file.write(dot_content)

if __name__ == '__main__':
    ctags_file = 'tags'
    nodes, edges = parse_ctags(ctags_file)
    dot_content = generate_dot(nodes, edges)
    save_dot(dot_content)
