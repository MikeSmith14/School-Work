//
//  ViewController.swift
//  Health Hearts at Home
//
//  Created by Luis Enrique Alvarez on 2/7/18.
//  Copyright © 2018 Luis Enrique Alvarez. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    @IBAction func homeScreenContacts(_ sender: Any) {
        performSegue(withIdentifier: "connectionCM", sender: self)
    }
    
}

